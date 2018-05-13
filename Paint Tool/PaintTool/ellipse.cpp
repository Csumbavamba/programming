#include "ellipse.h"

myShape::Ellipse::Ellipse(int hatchStyle, int penStyle, COLORREF penColor, COLORREF fillColor, int x, int y)
{
	this->hatchStyle = hatchStyle;
	this->penColor = penColor;
	this->fillColor = fillColor;
	this->penStyle = penStyle;
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

	HPEN customisedPen = CreatePen(penStyle, 1, penColor);
	SelectObject(hdc, customisedPen);
	
	HBRUSH customisedBrush;

	if (hatchStyle == -1)
	{
		// Create Solid Brush
		customisedBrush = CreateSolidBrush(fillColor);
	}
	else
	{
		// Create Hatched Brush
		customisedBrush = CreateHatchBrush(hatchStyle, fillColor);

	}

	SelectObject(hdc, customisedBrush);

	::Ellipse(hdc, startX, startY, endX, endY);

	DeleteObject(customisedPen);
	DeleteObject(customisedBrush);
}

void myShape::Ellipse::SetColor(COLORREF newColor)
{
}
