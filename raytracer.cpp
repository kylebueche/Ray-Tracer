#include <windows.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

void Update();

struct point // a value of 1 means 1 meter
{
    float x;
    float y;
    float z;
}

struct rotation // a value of 1 means 1 degree
{
    float x;
    float y;
    float z;
}

struct color // valid values are from 0 to 255
{
    char r;
    char g;
    char b;
    char a;
}

struct triangle
{
    point origin;
    color color;
    point v1;
    point v2;
    point v3;
}

struct ray
{
    point origin;
    rotation direction;

struct pixel
{
    point origin;;
    color color;
}

struct camera // this camera uses points for light in each pixel,
	      // but what if each pixel averaged a square grid of
	      // light akin to a real camera? (points don't exist,
	      // we just have really really small sensors in cams)
{
    pixel[3840][2160] pixelGrid;
    int pixelWidth;
    int pixelHeight;
    float sensorWidth;
    float sensorHeight
    float sensorDistance;
    point focusPoint;
    point origin;
    ray cameraRay;
}

void setSensorWidth(struct camera&, float);

void cameraUpdate(struct camera& thisCamera)
{
    float pixeltopixeldistance = thisCamera.sensorWidth / thisCamera.pixelWidth
    thisCamera.sensorHeight = pixeltopixeldistance * pixelHeight;
    int y;
    int z;
    for (y = 0; y < thisCamera.pixelWidth; y++)
    {
	for (z = 0; z < thisCamera.pixelHeight; z++)
	{
	    thisCamera.pixelGrid[y][z].origin.x = sensorDistance;
	    thisCamera.pixelGrid[y][z].origin.y = (y * pixeltopixeldistance) - (0.5 * pixelWidth * pixeltopixeldistance);
	    thisCamera.pixelGrid[y][z].origin.z = (y * pixeltopixeldistance) - (0.5 * pixelHeight * pixeltopixeldistance);
	}
    }
}

void cameraShoot(struct camera& thisCamera)
{
    
    int y;
    int z;
    for (y = 0; y < thisCamera.pixelWidth; y++)
    {
	for (z = 0; z < thisCamera.pixelHeight; z++)
	{
            thisCamera.pixelGrid[y][z].
	}
    }
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    HWND window_handle;
    WNDCLASSEX window_class_info;
    MSG win_event_messages;
    triangle triangle;

    ZeroMemory(&triangle, sizeof(Triangle));

    ZeroMemory(&camera, sizeof(Camera));
    Camera.endx = 1920;
    Camera.endy = 1080;
    Camera.pixelGrid
    //setSensorWidth(camera, 0.1);
    //setSensorDistance(camera, 0.1);

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

    while (GetMessage(&win_event_messages, NULL, 0, 0))
    {
        TranslateMessage(&win_event_messages);
        DispatchMessage(&win_event_messages);
    }

    return win_event_messages.wParam;
}

LRESULT CALLBACK WindowProc(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam)
{
    int window_width = LOWORD(lParam);
    int window_height = HIWORD(lParam);
    PAINTSTRUCT paint_struct;
    HDC hdc;
    switch(message)
    {
	case WM_PAINT:
        {
	    hdc = BeginPaint(window_handle, &paint_struct);
            SetPixel(hdc, camera);

	    EndPaint(window_handle, &paint_struct);
	    break;
	}
	case WM_SIZE:
	{
	    window_width = LOWORD(lParam);
	    window_height = HIWORD(lParam);
	    break;
	}
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
	    break;
        }
    }
    return DefWindowProc (window_handle, message, wParam, lParam);
}
