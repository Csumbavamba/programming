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


#ifndef __SHAPE_H__
#define __SHAPE_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>

class IShape
{
public:
	IShape();
	virtual ~IShape(){}

	virtual void Draw(HDC hdc) = 0;

	void SetStartX(int startX);
	void SetEndX(int endX);
	void SetStartY(int startY);
	void SetEndY(int endY);
	//void SetColor(COLORREF _newColor);

protected:
	int startX;
	int endX;
	int startY;
	int endY;
	//COLORREF m_ColorRef;
};

#endif