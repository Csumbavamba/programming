#include "canvas.h"
#include "shape.h"
#include "backBuffer.h"

Canvas::Canvas()
{
	backBuffer = new BackBuffer();
}

Canvas::~Canvas()
{
	for (int i = 0; i < vectorOfShapes.size(); i++)
	{
		delete vectorOfShapes.at(i);
	}

	// delete backBuffer;
}

bool Canvas::Initialise(HWND hwnd, int width, int height)
{
	this->hwnd = hwnd;

	backBuffer->Initialise(hwnd, width, height);

	//backBuffer->Clear();
	
	return true;
}

BackBuffer * Canvas::GetBackBuffer()
{
	return backBuffer;
}

bool Canvas::Draw()
{
	backBuffer->Clear();

	for (IShape * shape : vectorOfShapes)
	{
		shape->Draw(backBuffer->GetBufferHDC());
			// shape->Draw(hdc);
	}
	
	backBuffer->Present();
	
	return false;
}

void Canvas::Save(HWND hwnd)
{
	
}

void Canvas::AddShape(IShape * shape)
{
	vectorOfShapes.push_back(shape);
}

void Canvas::RemoveShape()
{
	if (!vectorOfShapes.empty())
	{
		vectorOfShapes.pop_back();
	}
	
}

void Canvas::AddStamp(Stamp * stamp)
{
	vectorOfStamps.push_back(stamp);
}
