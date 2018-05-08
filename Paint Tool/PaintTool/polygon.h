/***********************
  Bachelor of Software Engineering
  Media Design School
  Auckland
  New Zealand

  (c) 2018 Media Design School

  File Name   :   [Filename]
  Description :   [One line description of what is the file is for]
  Author      :   [Your name]
  Mail        :   [your.name]@mediadesign.school.nz
********************/

#ifndef __POLYGON_H__
#define __POLYGON_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>

#include "shape.h"

namespace myShape
{
	class Polygon : public IShape
	{
	public:
		Polygon(int hatchStyle, COLORREF fillColor, int penStyle, COLORREF penColor, int penWidth);
		Polygon();
		virtual ~Polygon();

		virtual void Draw(HDC hdc);
		void SetFillColor(COLORREF newColor);
		void SetPenColor(COLORREF newColor);
		void AddPoint(POINT * point);


	private:
		COLORREF fillColor;
		COLORREF penColor;
		POINT* pointList;
		int points;
		int hatchStyle;
		// int fillStyle;
		int penStyle;
		int penWidth;
	};
}


#endif