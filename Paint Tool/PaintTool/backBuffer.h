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

#pragma once
//Library Includes
#include <Windows.h>

class BackBuffer
{
public:
	BackBuffer();
	~BackBuffer();

	bool Initialise(HWND hwnd, int width, int height);

	HDC GetBufferHDC() const;

	int GetHeight() const;
	int GetWidth() const;

	void Clear();
	void Present();

private:
	BackBuffer(const BackBuffer&);
	BackBuffer& operator = (const BackBuffer&);

private:
	HWND hwnd;
	HDC bufferHDC;  //Handle to the in-memory DC for holding the backbuffer 
	HBITMAP bufferBitmap; //handle to the bitmap that represents the backbuffer
	HBITMAP oldBufferBitmap; //Used in select object to save the old bitmap.
	int width;
	int height;


};


