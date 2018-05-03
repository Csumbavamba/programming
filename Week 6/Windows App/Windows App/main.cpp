#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#define WINDOW_CLASS_NAME L"WINCLASS1"

LRESULT CALLBACK WindowProc(HWND handleToWindow,
							UINT message,
							WPARAM wParameter,
							LPARAM lParameter)
{
	/// This is the main message handler of the system
	// Used in WM_PAINT
	PAINTSTRUCT paintStruct; 
	HDC handleToDeviceContext;

	static int windowsOpened = 0;
	static int windowsClosed = 0;

	// What is the message?
	switch (message)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here
		windowsOpened++;
		// return success
		return (0);
	}
	break;

	case WM_PAINT:
	{
		// Simply validate the window
		handleToDeviceContext = BeginPaint(handleToWindow, &paintStruct);

		// You would do all the painting here...

		EndPaint(handleToWindow, &paintStruct);

		// Return Success
		return (0);
	}
	break;

	case WM_DESTROY:
	{
		windowsClosed++;

		if (windowsClosed >= windowsOpened)
		{
			// Kill the application, this sends 
			PostQuitMessage(0);
		}
		

		// Return success
		return (0);
	}
	break;

	default:break;
	} // End Switch

	// Process any messages that we did not take care of....
	
	return (DefWindowProc(handleToWindow, message, wParameter, lParameter));
}

int WINAPI WinMain(HINSTANCE handleToInstance, HINSTANCE handleToPreviousInstance, LPSTR commandLine, int commandShow)
{
	WNDCLASSEX windowClass; // This will hold the window we create

	HWND handleToWindow1;	// Generic window handle 1
	HWND handleToWindow2;

	MSG message;			// Generic message

	// First fill in the window class structure
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = handleToInstance;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor = NULL; // LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));

	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = WINDOW_CLASS_NAME;
	windowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&windowClass))
	{
		return (0);
	}

	handleToWindow1 = CreateWindowEx(	NULL,								// Extended style
										WINDOW_CLASS_NAME,					// Class
										L"WINDOW 1",						// Title
										WS_OVERLAPPEDWINDOW | WS_VISIBLE,
										0, 0,								// Initial x, y
										400, 400,							// Initial width, height
										NULL,								// Handle to Parent
										NULL,								// Handle to Menu
										handleToInstance,					// Instance of this application
										NULL);								// Extra creation parameter

	handleToWindow2 = CreateWindowEx(	NULL,								// Extended style
										WINDOW_CLASS_NAME,					// Class
										L"WINDOW 2",						// Title
										WS_OVERLAPPEDWINDOW | WS_VISIBLE,
										0, 400,								// Initial x, y
										400, 400,							// Initial width, height
										NULL,								// Handle to Parent
										NULL,								// Handle to Menu
										handleToInstance,					// Instance of this application
										NULL);								// Extra creation parameter

	// Check if window was created succesfully
	if (!handleToWindow1)
	{
		return (0);
	}

	// Enter main event Loop
	while ((GetMessage(&message, NULL, 0, 0)) > 0)
	{
		// Translate any accelerator keys...
		TranslateMessage(&message);

		// Send the message to the window proc
		DispatchMessage(&message);
	}

	// Return to window like this
	return (static_cast<int>(message.wParam));
}