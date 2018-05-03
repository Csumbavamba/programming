#include "canvas.h"
#include "shape.h"

Canvas::Canvas()
{
}

Canvas::~Canvas()
{
}

bool Canvas::Initialise(HWND hwnd, int width, int height)
{
	this->hwnd = hwnd;
	return false;
}

BackBuffer * Canvas::GetBackBuffer()
{
	return nullptr;
}

bool Canvas::Draw(int mouseX, int mouseY)
{
	HDC hdc = GetDC(hwnd);

	// Draw between these two
	for (IShape * shape : vectorOfShapes)
	{
		shape->Draw(hdc);
	}


	ReleaseDC(hwnd, hdc);
	return false;
}

void Canvas::Save(HWND hwnd)
{
}

void Canvas::AddShape(IShape * shape)
{
	vectorOfShapes.push_back(shape);
}

void Canvas::AddStamp(Stamp * stamp)
{
	vectorOfStamps.push_back(stamp);
}
