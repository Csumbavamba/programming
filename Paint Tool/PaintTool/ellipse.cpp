#include "ellipse.h"

myShape::Ellipse::Ellipse(COLORREF penColor, COLORREF fillColor, int x, int y)
{
	this->penColor = penColor;
	this->fillColor = fillColor;
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

	SelectObject(hdc, GetStockObject(DC_PEN));

	SetDCPenColor(hdc, penColor);
	


	SelectObject(hdc, GetStockObject(DC_BRUSH));

	SetDCBrushColor(hdc, fillColor);


	::Ellipse(hdc, startX, startY, endX, endY);
}

void myShape::Ellipse::SetColor(COLORREF newColor)
{
}
