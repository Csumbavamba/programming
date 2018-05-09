#include "line.h"

myShape::Line::Line(int style, int width, COLORREF newColor, int startX, int startY)
{
	this->style = style;
	this->width = width;
	color = newColor;
	this->startX = startX;
	this->startY = startY;
}

myShape::Line::Line()
{
}

myShape::Line::~Line()
{
}

void myShape::Line::Draw(HDC hdc)
{
	SelectObject(hdc, GetStockObject(DC_PEN));

	SetDCPenColor(hdc, color);

	MoveToEx(hdc, startX, startY, NULL); // Draw the line... 
	LineTo(hdc, endX, endY);
}

void myShape::Line::SetWidth(int width)
{
	this->width = width;
}
