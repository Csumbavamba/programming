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

	/*POINT * point1 = new POINT();
	point1->x = 10;
	point1->y = 10;
	POINT * point2 = new POINT();
	point2->x = 100;
	point2->y = 100;

	pointList[0] = *point1;
	pointList[1] = *point2;

	points = 2;*/

	
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

void myShape::Polygon::AddPoint(POINT * point)
{
	point->x = endX;
	point->y = endY;
	pointList[points] = *point;
	points++;
}
