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

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>

#include "shape.h"

enum BRUSHSTYLE
{
	NOSTYLE = -1,
	SOLID,
	HATCH
};

namespace myShape
{
	class Rectangle : public IShape
	{
	public:
		Rectangle(BRUSHSTYLE brushStyle, int hatchStyle, COLORREF fillColor, int penStyle, COLORREF penColor, int x, int y);
		Rectangle();
		virtual ~Rectangle();

		virtual void Draw(HDC hdc);
		void SetBrushStyle(BRUSHSTYLE brushStyle);
		void SetFillColor(COLORREF newColor);
		void SetPenStyle(int penStyle);
		void SetPenColor(COLORREF newColor);
		void SetHatchStyle(int hatchStyle);


	private:
		BRUSHSTYLE brushStyle;
		int hatchStyle;
		COLORREF fillColor;
		int penStyle;
		COLORREF penColor;
	};
}



#endif