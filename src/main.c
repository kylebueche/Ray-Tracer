#include <windows.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "mymath.h"
#include "vectormath.h"
#include "objects.h"
#include "lights.h"
#include "intersections.h"
#include "raytracing.h"

struct
{
    int width;
    int height;
    uint32_t *pixels;
} pixelGrid = {0};

LRESULT CALLBACK WindowProcessMessage(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam);

static bool quit = false;

static BITMAPINFO frame_bitmap_info;
static HBITMAP frame_bitmap = 0;
static HDC frame_device_context;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
    Ray ray = { 0 };
    Color skybox = { 0 };
    ObjectNode *objects = NULL;
    LightNode *lights = NULL;
    double camWidth;
    double camHeight;
    double camDepth;
    double pixelDist;
    double camWidthOffset;
    double camHeightOffset;
    int numberOfReflections;
    int x;
    int y;
    static WNDCLASS window_class = { 0 };
    static const wchar_t window_class_name[] = L"My Window Class";
    HWND window_handle;
    window_class.lpszClassName = (PCSTR)window_class_name;
    window_class.lpfnWndProc = WindowProcessMessage;
    window_class.hInstance = hInstance;

    frame_bitmap_info.bmiHeader.biSize = sizeof(frame_bitmap_info.bmiHeader);
    frame_bitmap_info.bmiHeader.biPlanes = 1;
    frame_bitmap_info.bmiHeader.biBitCount = 32;
    frame_bitmap_info.bmiHeader.biCompression = BI_RGB;
    frame_device_context = CreateCompatibleDC(0);

    RegisterClass(&window_class);

    window_handle = CreateWindow(
                            (PCSTR)window_class_name, "Graphics Engine", WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                            NULL, NULL, hInstance, NULL
                            );
    if (window_handle == NULL)
    {
        return -1;
    }
    else
    {
        ShowWindow(window_handle, nCmdShow);
	
    	camDepth = 1.0;
	    camWidth = 1.0;
        ray.position.x = 0.0;
    	ray.position.y = 0.0;
    	ray.position.z = 0.0;
        skybox = newColor(0.0, 0.2, 1.0);
        objects = malloc(sizeof(ObjectNode));
        *objects = newPlane(newVector(0.0, 0.0, -10.0), newVector(0.0, 0.0, 1.0), newColor(0.0, 0.3, 0.7), 0.5);
        objects->next = malloc(sizeof(ObjectNode));
        *(objects->next) = newSphere(newVector(10.0, 0.0, 0.0), 1.0, newColor(0.0, 6.0, 3.0), 0.5);
        lights = malloc(sizeof(LightNode));
        *lights = newSun(newVector(-1.0, -1.0, 1.0), newColor(1.0, 1.0, 1.0), 1.0);
        lights->next = malloc(sizeof(LightNode)); 
        *(lights->next) = newPointLight(newVector(10.0, 10.0, 0.0), newColor(0.5, 0.9, 0.9), 0.4);
        numberOfReflections = 2;

        while (!quit)
        {
            static MSG message = { 0 };
            while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
            {
                TranslateMessage(&message);
                DispatchMessage(&message);
            }

            /* This is where we do everything for the game. */

	        pixelDist = camWidth / pixelGrid.width;
	        camHeight = pixelDist * pixelGrid.height;
	        camWidthOffset = camWidth / 2.0;
	        camHeightOffset = camHeight / 2.0;
            for (x = 0; x < pixelGrid.width; x++)
            {
                for (y = 0; y < pixelGrid.height; y++)
                {
		            ray.direction.x = camDepth;
        		    ray.direction.y = x * pixelDist - camWidthOffset;
		            ray.direction.z = y * pixelDist - camHeightOffset;
		            vecNormalize(&ray.direction);
                    pixelGrid.pixels[(y * pixelGrid.width + x)] = colorTo24Bit(traceRay(ray, objects, lights, skybox, numberOfReflections));
                }
            }
            printf("|");
            InvalidateRect(window_handle, NULL, FALSE);
            UpdateWindow(window_handle);
        }
    }
    return 0;
}

LRESULT CALLBACK WindowProcessMessage(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
        case WM_QUIT:
        case WM_DESTROY:
        {
            quit = true;
        }
        break;
        
        case WM_PAINT:
        {
            static PAINTSTRUCT paint;
            static HDC device_context;
            device_context = BeginPaint(window_handle, &paint);
            BitBlt(device_context,
                    paint.rcPaint.left, paint.rcPaint.top,
                    paint.rcPaint.right - paint.rcPaint.left,
                    paint.rcPaint.bottom - paint.rcPaint.top,
                    frame_device_context,
                    paint.rcPaint.left, paint.rcPaint.top,
                    SRCCOPY);
            EndPaint(window_handle, &paint);
        }
        break;

        case WM_SIZE:
        {
            frame_bitmap_info.bmiHeader.biWidth = LOWORD(lParam);
            pixelGrid.width = LOWORD(lParam);
            frame_bitmap_info.bmiHeader.biHeight = HIWORD(lParam);
            pixelGrid.height = HIWORD(lParam);
            if (frame_bitmap)
            {
                DeleteObject(frame_bitmap);
            }
            frame_bitmap = CreateDIBSection(NULL, &frame_bitmap_info, DIB_RGB_COLORS, (void **) &pixelGrid.pixels, 0, 0);
            SelectObject(frame_device_context, frame_bitmap);
        }
        break;

        default:
        {
            return DefWindowProc(window_handle, message, wParam, lParam);
        }
        break;
    }
    return 0;
}
