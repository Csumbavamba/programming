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

#ifndef __CANVAS_H__
#define __CANVAS_H__

//	Library Includes
#include <windows.h>
#include <windowsx.h>
#include <vector>

typedef enum
{
	LINE = 0,
	BOX,
	ELLIPSE,
	MAX_SHAPE
}EShape;

class IShape; //Forward Declaration
class Line;
class Stamp;
class BackBuffer;

class Canvas
{
public:
	Canvas();
	~Canvas();
	bool Initialise(HWND hwnd, int width, int height);
	BackBuffer* GetBackBuffer();
	bool Draw(int mouseX, int mouseY);
	void Save(HWND hwnd);
	void AddShape(IShape*);
	void AddStamp(Stamp*);
	
private:
	BackBuffer* backBuffer; // A canvas has a backbuffer.
	std::vector<Stamp*> vectorOfStamps;
	std::vector<IShape*> vectorOfShapes;
	HWND hwnd;
};

#endif