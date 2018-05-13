#include "canvas.h"
#include "shape.h"
#include "backBuffer.h"

Canvas::Canvas()
{
}

Canvas::~Canvas()
{
	for (int i = 0; i < vectorOfShapes.size(); i++)
	{
		delete vectorOfShapes.at(i);
	}

	delete backBuffer;
}

bool Canvas::Initialise(HWND hwnd, int width, int height)
{
	this->hwnd = hwnd;

	backBuffer = new BackBuffer();
	backBuffer->Initialise(hwnd, width, height);
	
	return false;
}

BackBuffer * Canvas::GetBackBuffer()
{
	return backBuffer;
}

bool Canvas::Draw(int mouseX, int mouseY)
{


	for (IShape * shape : vectorOfShapes)
	{
		shape->Draw(backBuffer->GetBufferHDC());
		// shape->Draw(hdc);
	}

	
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
