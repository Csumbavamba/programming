#include "backBuffer.h"

BackBuffer::BackBuffer()
{
	hwnd = NULL;
	bufferHDC = NULL;
	bufferBitmap = NULL;
	width = NULL;
	height = NULL;
}

BackBuffer::~BackBuffer()
{
	// Do cleanup here
	SelectObject(bufferHDC, oldBufferBitmap);
	DeleteObject(bufferBitmap);
	DeleteDC(bufferHDC);
}

bool BackBuffer::Initialise(HWND hwnd, int width, int height)
{

	// Initialize the main variables
	this->hwnd = hwnd;

	// this->width = width;
	// this->height = height;


	RECT desktop;
	const HWND handleToDesktop = GetDesktopWindow();
	GetWindowRect(handleToDesktop, &desktop);
	this->width = desktop.right;
	this->height = desktop.bottom;

	HDC compatibleHDC = GetDC(hwnd);

	bufferHDC = CreateCompatibleDC(compatibleHDC);
	bufferBitmap = CreateCompatibleBitmap(compatibleHDC, desktop.right, desktop.bottom);

	oldBufferBitmap = static_cast<HBITMAP>(SelectObject(bufferHDC, bufferBitmap));

	ReleaseDC(hwnd, compatibleHDC);

	// Clear buffer after drawing
	Clear();

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
	HBRUSH oldBrush = static_cast<HBRUSH>(SelectObject(bufferHDC, GetStockObject(WHITE_BRUSH)));
	RECT rect;

	

	rect.top = 0;
	rect.left = 0;
	rect.right = width;
	rect.bottom = height;

	FillRect(bufferHDC, &rect, oldBrush);
	SelectObject(bufferHDC, oldBrush);
}

void BackBuffer::Present()
{
	// Get the image on the screen
	RECT rect;
	GetClientRect(hwnd, &rect);
	
	HDC hdc = GetDC(hwnd);

	BitBlt(hdc, 0, 0, rect.right, rect.bottom, bufferHDC, 0, 0, SRCCOPY);

	ReleaseDC(hwnd, hdc);
}
