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

class Rectangle : public IShape
{
public:
	Rectangle(BRUSHSTYLE _iBrushStyle, int _iHatchStyle, COLORREF _FillColor, int _iPenStyle, COLORREF _PenColor, int _X, int _Y);
	Rectangle();
	virtual ~Rectangle();

	virtual void Draw(HDC _hdc);
	void SetBrushStyle(BRUSHSTYLE _brushStyle);
	void SetFillColor(COLORREF _newColor);
	void SetPenStyle (int _iPenStyle);
	void SetPenColor(COLORREF _newColor);
	void SetHatchStyle(int _iHatchStyle);
	

private:
	BRUSHSTYLE m_iBrushStyle;
	int m_iHatchStyle;
	COLORREF m_iFillColor;
	int m_iPenStyle;
	int m_iPenColor;
	COLORREF m_Color;
};

#endif