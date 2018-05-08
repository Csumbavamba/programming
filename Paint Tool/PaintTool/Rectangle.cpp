// #include <Windows.h>

#include "rectangle.h"
#include "shape.h"

myShape::Rectangle::Rectangle(BRUSHSTYLE brushStyle, int hatchStyle, COLORREF fillColor, int penStyle, COLORREF penColor, int x, int y)
{
	this->brushStyle = brushStyle;
	this->hatchStyle = hatchStyle;
	this->fillColor = fillColor;
	this->penStyle = penStyle;
	this->penColor = penColor;
	startX = x;
	startY = y;
}

myShape::Rectangle::Rectangle()
{
}

myShape::Rectangle::~Rectangle()
{
}

void myShape::Rectangle::Draw(HDC hdc)
{
	//MoveToEx(hdc, startX, startY, NULL); // Draw Rectangle
	::Rectangle(hdc, startX, startY, endX, endY);
}

void myShape::Rectangle::SetBrushStyle(BRUSHSTYLE brushStyle)
{
}

void myShape::Rectangle::SetFillColor(COLORREF newColor)
{
}

void myShape::Rectangle::SetPenStyle(int penStyle)
{
}

void myShape::Rectangle::SetPenColor(COLORREF newColor)
{
}

void myShape::Rectangle::SetHatchStyle(int hatchStyle)
{
}
