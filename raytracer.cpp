#include <windows.h>
#include <cmath>
#include "raytracer.h"

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

void RenderFrame(HWND&, HDC&, struct Triangle&, struct Camera&);

void RenderFrame(HWND& window_handle, struct Camera& camera, struct Triangle& triangle)
{
    float length;
    int x;
    int y;
    Point pixelPoint;
    Point E1;
    Point E2;

    Color colorVal;
    Ray ray;
    PAINTSTRUCT paint_struct;
    HDC hdc = BeginPaint(window_handle, &paint_struct);
    float pixeltopixeldistance = camera.sensorWidth / camera.pixelWidth;
    camera.sensorHeight = pixeltopixeldistance * camera.pixelHeight;
    ray.origin = camera.origin;
    for (x = 0; x < camera.pixelWidth; x++)
    {
	for (y = 0; y < camera.pixelHeight; y++)
	{
	    // Background color
	    colorVal.r = 0;
	    colorVal.g = 10;
	    colorVal.b = 200;
	    // Set direction of the ray based on where the pixel should be relative to the origin
	    ray.direction.x = camera.sensorDistance - ray.origin.x;
	    ray.direction.y = (x * pixeltopixeldistance) - (0.5 * camera.pixelWidth * pixeltopixeldistance) - ray.origin.y;
	    ray.direction.z = (y * pixeltopixeldistance) - (0.5 * camera.pixelHeight * pixeltopixeldistance) - ray.origin.z;
	    // Normalize the vector
            length = std::sqrt(ray.direction.x * ray.direction.x
			     + ray.direction.y * ray.direction.y
			     + ray.direction.z * ray.direction.z);
	    ray.direction.x = ray.direction.x / length;
	    ray.direction.y = ray.direction.y / length;
	    ray.direction.z = ray.direction.z / length;

	    SetPixel(hdc, x, y, RGB(colorVal.r, colorVal.g, colorVal.b));
	}
    }
    EndPaint(window_handle, &paint_struct);
    InvalidateRect(window_handle, NULL, TRUE);
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    HWND window_handle;
    WNDCLASSEX window_class_info;
    MSG win_event_messages;
    
    struct Camera camera;

    struct Triangle triangle;

    ZeroMemory(&triangle, sizeof(struct Triangle));

    ZeroMemory(&camera, sizeof(struct Camera));

    camera.sensorDistance = 0.1;
    camera.sensorWidth = 0.1;

    ZeroMemory(&window_class_info, sizeof(WNDCLASSEX));
    
    window_class_info.cbSize = sizeof(WNDCLASSEX);
    window_class_info.style = CS_HREDRAW | CS_VREDRAW;
    window_class_info.lpfnWndProc = WindowProc;
    window_class_info.hInstance = hInstance;
    window_class_info.hCursor = LoadCursor(NULL, IDC_ARROW);
    window_class_info.hbrBackground = (HBRUSH) COLOR_WINDOW;
    window_class_info.lpszClassName = "WindowClass1";    
    
    RegisterClassEx(&window_class_info);
    
    window_handle = CreateWindowEx(NULL,
                                   "WindowClass1",
				   "Lesgooooooooo",
				   WS_OVERLAPPEDWINDOW,
				   300,
				   300,
				   700,
				   400,
				   NULL,
				   NULL,
				   hInstance,
				   NULL);

    ShowWindow(window_handle, nCmdShow);

    while (true)
    {
        while (GetMessage(&win_event_messages, NULL, 0, 0))
        {
            TranslateMessage(&win_event_messages);
            DispatchMessage(&win_event_messages);
        }
	camera.pixelWidth = LOWORD(win_event_messages.lParam);
	camera.pixelHeight = HIWORD(win_event_messages.lParam);
	RenderFrame(window_handle, camera, triangle);
    }
    return win_event_messages.wParam;
}

LRESULT CALLBACK WindowProc(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
	    break;
        }
    }
    return DefWindowProc(window_handle, message, wParam, lParam);
}
