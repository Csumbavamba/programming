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

#ifndef __LINE_H__
#define __LINE_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>

#include "shape.h"

namespace myShape
{
	class Line : public IShape
	{
	public:
		//Line(int _iStartX, int _iStartY, int _iEndX, int _iEndY, COLORREF _newColour, int _iStyle, int _iWidth); 
		Line(int style, int width, COLORREF newColour, int startX, int startY);
		Line();
		virtual ~Line();

		virtual void Draw(HDC hdc);
		void SetWidth(int width);


	private:

		int style;
		int width;
		COLORREF colour;
	};
}


#endif