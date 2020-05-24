#include "CBallsTimeLmited.h"
CBallsTimeLmited::CBallsTimeLmited()
{
	this->hbrush = CreateSolidBrush(RGB(255, 255, 0));
}

CBallsTimeLmited::~CBallsTimeLmited()
{
	//if(this->timeLife > 5000)
	//DeleteBrush(this->hbrush);
	DeleteBrush(this->hbrush);
	ReleaseDC(this->hwnd,this->hdc);
		
		
		
}

void CBallsTimeLmited::SetColor(unsigned char r, unsigned char g, unsigned char b)
{
	DeleteBrush(this->hbrush);
	this->hbrush = CreateSolidBrush(RGB(r, g, b));

}

void CBallsTimeLmited::Draw(HDC hdc)
{
	HBRUSH old = SelectBrush(hdc, this->hbrush);
	Ellipse(hdc, x - r, y - r, x + r, y + r);
	SelectBrush(hdc, old);
}

//void CBallsTimeLmited::SetHWND(HWND hwnd)
//{
//	this->hwnd = hwnd;
//}


