#include "backBuffer.h"

BackBuffer::BackBuffer()
{
}

BackBuffer::~BackBuffer()
{
	
}

bool BackBuffer::Initialise(HWND hwnd, int width, int height)
{
	this->hwnd = hwnd;

	this->width = width;
	this->height = height;

	bufferHDC = GetDC(hwnd);

	// TODO FIX BACKBUFFER


	HDC compatibleHDC = CreateCompatibleDC(bufferHDC);
	// Create the HBITMAP "canvas", or surface on which we will draw.
	bufferBitmap = CreateCompatibleBitmap(bufferHDC, width, height);

	oldBufferBitmap = static_cast<HBITMAP>(SelectObject(compatibleHDC, bufferBitmap));

	BitBlt(
		bufferHDC, // Destination HDC
		0,
		0,
		width,
		height,
		compatibleHDC, // Source HDC
		0,
		0,
		SRCCOPY
	);

	SelectObject(compatibleHDC, oldBufferBitmap);

	DeleteObject(oldBufferBitmap);

	DeleteDC(compatibleHDC);



	ReleaseDC(hwnd, bufferHDC);

	return true;
}

HDC BackBuffer::GetBufferHDC() const
{
	return bufferHDC;
}

int BackBuffer::GetHeight() const
{
	return height;
}

int BackBuffer::GetWidth() const
{
	return width;
}

void BackBuffer::Clear()
{
}

void BackBuffer::Present()
{
	
}

//BackBuffer & BackBuffer::operator=(const BackBuffer &)
//{
//	// TODO: insert return statement here
//}
