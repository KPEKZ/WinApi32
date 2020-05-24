#include "CColoredBall.h"

CColoredBall::CColoredBall()
{
	this->hBrush = CreateSolidBrush(RGB(0, 0, 0));
}

CColoredBall::~CColoredBall()
{
	DeleteBrush(this->hBrush);
}

void CColoredBall::SetColor(unsigned char r, unsigned char g, unsigned char b)
{
	DeleteBrush(this->hBrush);
	this->hBrush = CreateSolidBrush(RGB(r, g, b));
	
}

void CColoredBall::Draw(HDC hdc)
{
	HBRUSH old = SelectBrush(hdc, this->hBrush);
	Ellipse(hdc, x - r, y - r, x + r, y + r);
	SelectBrush(hdc, old);
}

