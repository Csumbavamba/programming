#include "shape.h"

IShape::IShape()
{
}

void IShape::SetStartX(int startX)
{
	this->startX = startX;
}

void IShape::SetEndX(int endX)
{
	this->endX = endX;
}

void IShape::SetStartY(int startY)
{
	this->startY = startY;
}

void IShape::SetEndY(int endY)
{
	this->endY = endY;
}
