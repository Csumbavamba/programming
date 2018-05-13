#include "polygon.h"
#include "shape.h"

myShape::Polygon::Polygon(int hatchStyle, COLORREF fillColor, int penStyle, COLORREF penColor, int penWidth)
{
	this->hatchStyle = hatchStyle;
	this->fillColor = fillColor;
	this->penStyle = penStyle;
	this->penColor = penColor;
	this->penWidth = penWidth;

	points = 0;
	this->pointList = new POINT[20];

	
}

myShape::Polygon::Polygon()
{
	delete [] pointList;
}

myShape::Polygon::~Polygon()
{
}

void myShape::Polygon::Draw(HDC hdc)
{

	HPEN customisedPen = CreatePen(penStyle, penWidth, penColor);
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

	::Polygon(hdc, pointList, points);

	DeleteObject(customisedPen);
	DeleteObject(customisedBrush);
}

void myShape::Polygon::SetFillColor(COLORREF newColor)
{
	fillColor = newColor;
}

void myShape::Polygon::SetPenColor(COLORREF newColor)
{
	penColor = newColor;
}

void myShape::Polygon::AddPoint(POINT * point)
{
	point->x = endX;
	point->y = endY;
	pointList[points] = *point;
	points++;
}
