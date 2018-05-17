#include "stamp.h"

Stamp::Stamp()
{
}

Stamp::Stamp(HINSTANCE hInstance, wchar_t * filename, int x, int y)
{
	startX = x;
	startY = y;

	bitMap = reinterpret_cast<HBITMAP>(LoadBitmap(hInstance, filename));

	GetObject(bitMap, sizeof(BITMAP), &bitMapStructure);
}

Stamp::~Stamp()
{
}

void Stamp::Draw(HDC hdc)
{
	HDC bitMapHDC;

	bitMapHDC = CreateCompatibleDC(NULL);
	SelectObject(bitMapHDC, bitMap);

	SetStretchBltMode(hdc, HALFTONE);
	StretchBlt(hdc, startX, startY, 150, 150, bitMapHDC, 0, 0, bitMapStructure.bmWidth, bitMapStructure.bmHeight, SRCCOPY);

	DeleteDC(bitMapHDC);
}
