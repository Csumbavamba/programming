/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2018 Media Design School

  File Name   :   [Filename]
  Description :   [One line description of what is the file is for]
  Author      :   [Your name]
  Mail        :   [your.name]@mediadesign.school.nz
********************/

//#define WIN32_LEAN_AND_MEAN

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.

#include "resource.h"
#include "shape.h"
#include "line.h"
#include "canvas.h"
#include "rectangle.h"
#include "ellipse.h"
#include "polygon.h"
#include "stamp.h"
#include "backBuffer.h"

#define WINDOW_CLASS_NAME L"WINCLASS1"

//Global variables
HINSTANCE globalHandleToInstance;
Canvas* globalCanvas;
IShape* globalShape = nullptr;
HMENU globalMenu;
myShape::Polygon * polygon;
COLORREF penColor = RGB(0, 0, 0);
COLORREF brushColor = RGB(255, 255, 255);

// bool mouseDown = false;
int mouseX, mouseY;

//Enum to decalre the type of tool supported by the application.
enum ESHAPE
{
	FREEHAND = 0,
	LINESHAPE,
	RECTANGLESHAPE,
	ELLIPSESHAPE,
	POLYGONSHAPE,
	STAMP
};





void GameLoop()
{
	globalCanvas->Draw(mouseX, mouseY);
	
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND hwnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT paintStruct; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.

	static ESHAPE currentShape = FREEHAND;

	static int currentPolygonPoints = 0;
	
	switch (message)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.
		
		globalCanvas = new Canvas();
		globalCanvas->Initialise(hwnd, 1500, 800);

		// Return Success.
		return (0);
	}
	break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &paintStruct);

		// Set Pen here
		// HGDIOBJ original = NULL; // initialize original object here

		// Save original
		// original = SelectObject(hdc, GetStockObject(DC_PEN));


		// Select pen
		// SelectObject(hdc, GetStockObject(DC_PEN));
		// Set Pen color

		//switch (currentPenColor)
		//{
		//case BLACKPEN:
		//{
		//	SetDCPenColor(hdc, RGB(0, 0, 0));
		//	break;
		//}
		//case WHITEPEN:
		//{
		//	SetDCPenColor(hdc, RGB(255, 255, 255));
		//	break;
		//}
		//case REDPEN:
		//{
		//	SetDCPenColor(hdc, RGB(255, 0, 0));
		//	break;
		//}
		//case GREENPEN:
		//{
		//	SetDCPenColor(hdc, RGB(0, 255, 0));
		//	break;
		//}
		//case BLUEPEN:
		//{
		//	SetDCPenColor(hdc, RGB(0, 0, 255));
		//	break;
		//}
		//default:
		//	SetDCPenColor(hdc, RGB(255, 255, 255)); // Set brush black		
		//}


		// Select Brush
		// SelectObject(hdc, GetStockObject(DC_BRUSH));
		// Set Brush color

		//switch (currentBrushColor)
		//{
		//
		//case BLACKBRUSH:
		//{
		//	SetDCBrushColor(hdc, RGB(0, 0, 0));
		//	break;
		//}
		//case WHITEBRUSH:
		//{
		//	SetDCBrushColor(hdc, RGB(255, 255, 255));
		//	break;
		//}
		//case REDBRUSH:
		//{
		//	SetDCBrushColor(hdc, RGB(255, 0, 0)); // Set brush red
		//	break;
		//}
		//case GREENBRUSH:
		//{
		//	SetDCBrushColor(hdc, RGB(0, 255, 0));
		//	break;
		//}
		//case BLUEBRUSH:
		//{
		//	SetDCBrushColor(hdc, RGB(0, 0, 255));
		//	break;
		//}
		//default:
		//	SetDCBrushColor(hdc, RGB(0, 0, 0)); // Set brush white
		//}

		

		if(globalCanvas != nullptr)
		globalCanvas->Draw(mouseX, mouseY);

		// SelectObject(hdc, original);
		
		EndPaint(hwnd, &paintStruct);
		// Return Success.
		return (0);
	}
	break;

	case WM_RBUTTONDOWN:
	{
		if (currentShape == POLYGONSHAPE && globalShape != nullptr)
		{

			polygon = dynamic_cast<myShape::Polygon*>(globalShape);

			polygon->SetEndX(mouseX);
			polygon->SetEndY(mouseY);

			POINT * point = new POINT();
			polygon->AddPoint(point);
			currentPolygonPoints++;
		}
		return (0);
	}

	case WM_RBUTTONDBLCLK:
	{
		globalShape = nullptr;
		return (0);
	}
	break;

	case WM_LBUTTONDOWN:
	{
		// Get the position of the mouse
		mouseX = static_cast<int>(LOWORD(lParam));
		mouseY = static_cast<int>(HIWORD(lParam));
		// mouseDown = true;

			switch (currentShape)
			{
			case LINESHAPE:
			{
				if (!globalShape)
				{
					globalShape = new myShape::Line(PS_SOLID, 1, penColor, mouseX, mouseY); 
					globalCanvas->AddShape(globalShape);
				}
			}
			break;

			case RECTANGLESHAPE:
			{
				if (!globalShape)
				{
					globalShape = new myShape::Rectangle(NOSTYLE, 1, brushColor, 0, penColor, mouseX, mouseY);
					globalShape->SetEndX(mouseX);
					globalShape->SetEndY(mouseY);
					globalCanvas->AddShape(globalShape);
				}
			}
			break;

			case ELLIPSESHAPE:
			{
				if (!globalShape)
				{
					globalShape = new myShape::Ellipse(penColor, brushColor, mouseX, mouseY);
					globalShape->SetEndX(mouseX);
					globalShape->SetEndY(mouseY);
					globalCanvas->AddShape(globalShape);
				}
			}
			break;

			case POLYGONSHAPE:
			{
				if (!globalShape)
				{
					globalShape = new myShape::Polygon(1, brushColor, 1, penColor, 1);
					globalShape->SetEndX(mouseX);
					globalShape->SetEndY(mouseY);
					globalCanvas->AddShape(globalShape); // TODO Add Points somewhere

				}
			}
			break;

			default:
			{
				break;
			}
		
			}
			InvalidateRect(hwnd, NULL, TRUE);
			// Return success.
			return (0);

	}
	break;

	case WM_LBUTTONUP:
	{
		mouseX = static_cast<int>(LOWORD(lParam));
		mouseY = static_cast<int>(HIWORD(lParam));

		// mouseDown = false;
		if (globalShape)
		{
			globalShape->SetEndX(mouseX);
			globalShape->SetEndY(mouseY);
			//InvalidateRect(hwnd, NULL, TRUE);			
		}

		if (currentShape != POLYGONSHAPE)
			globalShape = nullptr;


		
		return (0);
	}
	break;

	case WM_MOUSEMOVE:
	{
		// Get the position of the mouse
		mouseX = static_cast<int>(LOWORD(lParam));
		mouseY = static_cast<int>(HIWORD(lParam));

		// Get the button state
		// int buttons = static_cast<int>(wParam);

		// Test if left mouse button is down
		if (MK_LBUTTON)
		{
			if (globalShape != nullptr)
			{
				globalShape->SetEndX(mouseX);
				globalShape->SetEndY(mouseY);
				InvalidateRect(hwnd, NULL, TRUE);
			}
		}

		// Return success.
		return (0);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ID_FILE_EXIT:
		{
			PostQuitMessage(0);
			break;
		}
		case ID_HELP_ABOUT:
		{
			MessageBox(hwnd, L"This paint tool was developed by .............", L"Zsombor Pirok", MB_OK | MB_ICONINFORMATION);
			break;
		}
		case ID_SHAPE_LINE:
		{
			currentShape = ESHAPE::LINESHAPE;
			break;
		}
		case ID_SHAPE_R:
		{
			currentShape = ESHAPE::RECTANGLESHAPE;
			break;
		}
		case ID_SHAPE_ELLIPSE:
		{
			currentShape = ESHAPE::ELLIPSESHAPE;
			break;
		}
		case ID_SHAPE_POLYGON:
		{
			currentShape = ESHAPE::POLYGONSHAPE;
			break;
		}



		case ID_PENCOLOR_BLACK:
		{
			penColor = RGB(0, 0, 0);
			break;
		}
		case ID_PENCOLOR_WHITE:
		{
			penColor = RGB(255, 255, 255);
			break;
		}
		case ID_PENCOLOR_RED:
		{
			penColor = RGB(255, 0, 0);
			break;
		}
		case ID_PENCOLOR_GREEN:
		{
			break;
		}
		case ID_PENCOLOR_BLUE:
		{
			break;
		}



		case ID_BRUSHCOLOR_WHITE:
		{
			brushColor = RGB(0, 0, 0);
			break;
		}
		case ID_BRUSHCOLOR_BLACK:
		{
			brushColor = RGB(255, 255, 255);
			break;
		}
		case ID_BRUSHCOLOR_RED:
		{
			brushColor = RGB(255, 0, 0);
			break;
		}
		case ID_BRUSHCOLOR_GREEN:
		{
			break;
		}
		case ID_BRUSHCOLOR_BLUE:
		{
			break;
		}
		
			
			
			
			
			
			
			
			
			


		default:
			break;
		}
		return(0);
	}
	break;
	case WM_DESTROY:
	{
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		delete globalCanvas;

		// Return success.
		return (0);
	}
	break;

		default:break;
	} // End switch.

	  // Process any messages that we did not take care of...

	return (DefWindowProc(hwnd, message, wParam, lParam));
}

int WINAPI WinMain(HINSTANCE handleToInstance,
	HINSTANCE handleToPreviousInstance,
	LPSTR longCommandLine,
	int commandShow)
{
	WNDCLASSEX winClass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG message;             // Generic message.

	globalHandleToInstance = handleToInstance;
	// First fill in the window class structure.
	winClass.cbSize = sizeof(WNDCLASSEX);
	winClass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winClass.lpfnWndProc = WindowProc;
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 0;
	winClass.hInstance = handleToInstance;
	winClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground =
		static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	winClass.lpszMenuName = NULL;
	winClass.lpszClassName = WINDOW_CLASS_NAME;
	winClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winClass))
	{
		return (0);
	}

	globalMenu = LoadMenu(handleToInstance, MAKEINTRESOURCE(IDR_MENU1));
	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"My Paint Tool",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100,                    // Initial x,y.
		1500, 800,                // Initial width, height.
		NULL,                   // Handle to parent.
		globalMenu,                   // Handle to menu.
		handleToInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}



	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (message.message == WM_QUIT)
			{
				break;
			}

			// Translate any accelerator keys.
			TranslateMessage(&message);
			// Send the message to the window proc.
			DispatchMessage(&message);
		}

		// Main game processing goes here.
		//GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(message.wParam));
}
