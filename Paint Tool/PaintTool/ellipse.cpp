#include "ellipse.h"

myShape::Ellipse::Ellipse(COLORREF newColor, int x, int y)
{
	color = newColor;
	startX = x;
	startY = y;
}

myShape::Ellipse::Ellipse()
{
}

myShape::Ellipse::~Ellipse()
{
}

void myShape::Ellipse::Draw(HDC hdc)
{
	::Ellipse(hdc, startX, startY, endX, endY);
}

void myShape::Ellipse::SetColor(COLORREF newColor)
{
}
