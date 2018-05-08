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
	::Polygon(hdc, pointList, points);
}

void myShape::Polygon::SetFillColor(COLORREF newColor)
{
	fillColor = newColor;
}

void myShape::Polygon::SetPenColor(COLORREF newColor)
{
	penColor = newColor;
}

void myShape::Polygon::AddPoint(POINT point)
{
	pointList[points] = point;
	points++;
}
