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


#ifndef __ELLIPSE_H__
#define __ELLIPSE_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>

#include "shape.h"

namespace myShape
{
	class Ellipse : public IShape
	{
	public:
		Ellipse(int hatchStyle, int penStyle, COLORREF penColor, COLORREF fillColor, int x, int y);
		Ellipse();
		virtual ~Ellipse();

		virtual void Draw(HDC hdc);
		void SetColor(COLORREF newColor);


	private:
		COLORREF penColor;
		COLORREF fillColor;
		int hatchStyle;
		int penStyle;
	};
}



#endif