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
int currentPolygonPoints = 0;
COLORREF penColor = RGB(0, 0, 0);
COLORREF brushColor = RGB(255, 255, 255);
int penWidth = 1;
int penStyle = PS_SOLID;
int hatchStyle = -1;
BRUSHSTYLE brushStyle = NOSTYLE;
CHOOSECOLOR chosenColor;
COLORREF customColors[16];

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



void AddPolygonPoint()
{
	polygon = dynamic_cast<myShape::Polygon*>(globalShape);

	polygon->SetEndX(mouseX);
	polygon->SetEndY(mouseY);

	POINT * point = new POINT();
	polygon->AddPoint(point);
	currentPolygonPoints++;
}

void GameLoop()
{
	globalCanvas->Draw(mouseX, mouseY);
	
	//One frame of game logic occurs here...
}

void CheckSelectedMenuItem(int selectedMenuItem, int& lastMenuItem)
{
	if (lastMenuItem != 0)
		CheckMenuItem(globalMenu, lastMenuItem, MF_UNCHECKED);

	CheckMenuItem(globalMenu, selectedMenuItem, MF_CHECKED);
	lastMenuItem = selectedMenuItem;
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

	static int lastSelectedMenuItem;
	
	switch (message)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.
		
		globalCanvas = new Canvas();
		globalCanvas->Initialise(hwnd, 1500, 800);
		// globalCanvas->GetBackBuffer()->Initialise(hwnd, 1500, 800);

		// Initialize choosecolor
		ZeroMemory(&chosenColor, sizeof(chosenColor));
		chosenColor.lStructSize = sizeof(chosenColor);
		chosenColor.hwndOwner = hwnd;
		chosenColor.lpCustColors = (LPDWORD)customColors;
		chosenColor.rgbResult = penColor;
		chosenColor.Flags = CC_FULLOPEN || CC_RGBINIT;

		// Return Success.
		return (0);
	}
	break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hwnd, &paintStruct);


		if(globalCanvas != nullptr)
		globalCanvas->Draw(mouseX, mouseY);
		

		EndPaint(hwnd, &paintStruct);
		// Return Success.
		return (0);
	}
	break;

	case WM_RBUTTONDOWN:
	{
		if (currentShape == POLYGONSHAPE && globalShape != nullptr)
		{

			AddPolygonPoint();
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
					globalShape = new myShape::Line(penStyle, penWidth, penColor, mouseX, mouseY); 
					globalCanvas->AddShape(globalShape);
				}
			}
			break;

			case RECTANGLESHAPE:
			{
				if (!globalShape)
				{
					globalShape = new myShape::Rectangle(brushStyle, hatchStyle, brushColor, penStyle, penColor, mouseX, mouseY);
					globalShape->SetEndX(mouseX); 
					globalShape->SetEndY(mouseY);
					globalCanvas->AddShape(globalShape); // TODO simplify method (setEndXY + Add shape can be called after switch)
				}
			}
			break;

			case ELLIPSESHAPE:
			{
				if (!globalShape)
				{
					globalShape = new myShape::Ellipse(hatchStyle, penStyle, penColor, brushColor, mouseX, mouseY);
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
					globalShape = new myShape::Polygon(hatchStyle, brushColor, penStyle, penColor, penWidth);
					globalShape->SetEndX(mouseX);
					globalShape->SetEndY(mouseY);
					globalCanvas->AddShape(globalShape); 
					if (currentPolygonPoints == 0)
						AddPolygonPoint();

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

		// SHAPES
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


		// PEN COLOR
		case ID_PEN_COLOR:
		{
			ChooseColor(&chosenColor);
			penColor = chosenColor.rgbResult;
			break;
		}
		


		// PEN WIDTH FOR LINE
		case ID_WIDTH_1:
		{
			penWidth = 1;
			break;
		}
		case ID_WIDTH_2:
		{
			penWidth = 2;
			break;
		}
		case ID_WIDTH_3:
		{
			penWidth = 3;
			break;
		}

		// PEN STYLE
		case ID_STYLE_INVISIBLE:
		{
			penStyle = PS_NULL;
			break;
		}
		case ID_STYLE_SOLID:
		{
			penStyle = PS_SOLID;
			break;
		}
		case  ID_STYLE_DASHED:
		{
			penStyle = PS_DASH;
			break;
		}
		case ID_STYLE_DOTTED:
		{
			penStyle = PS_DOT;
			break;
		}


		// BRUSH COLOR
		case ID_BRUSH_COLOR:
		{
			ChooseColor(&chosenColor);
			brushColor = chosenColor.rgbResult;
			break;
		}

		// Brush style
		case ID_STYLE_NOHATCH:
		{
			brushStyle = NOSTYLE;
			hatchStyle = -1;
			break;
		}
		case ID_STYLE_DIAGONAL:
		{
			brushStyle = HATCH;
			hatchStyle = HS_BDIAGONAL;
			break;
		}
		case ID_STYLE_CROSS:
		{
			brushStyle = HATCH;
			hatchStyle = HS_CROSS;
			break;
		}
		case ID_STYLE_HORIZONTALHATCH:
		{
			brushStyle = HATCH;
			hatchStyle = HS_HORIZONTAL;
			break;
		}
		case ID_STYLE_VERTICALHATCH:
		{
			brushStyle = HATCH;
			hatchStyle = HS_VERTICAL;
			break;
		}
		
			
			
			
			
			
			
			
			
			


		default:
			break;
		}

		CheckSelectedMenuItem(LOWORD(wParam), lastSelectedMenuItem);


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
