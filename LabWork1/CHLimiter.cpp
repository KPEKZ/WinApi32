#include "CHLimiter.h"

CHLimiter::CHLimiter(int xmin, int xmax, int y)
{
	this->xmax = xmax;
	this->xmin = xmin;
	this->y = y;

}

CHLimiter::~CHLimiter()
{
}

void CHLimiter::Draw(HDC hdc)
{
	::MoveToEx(hdc, this->xmin, this->y, NULL);
	::LineTo(hdc, this->xmax, this->y);
}

int CHLimiter::GetMaxX()
{
	return this->xmax;
}

int CHLimiter::GetMinX()
{
	return this->xmin;
}

int CHLimiter::GetY()
{
	return this->y;
}

void CHLimiter::MoveX(int inc)
{
	this->xmax -= inc;
	this->xmin -= inc;
}

void CHLimiter::MoveY(int inc)
{
	this->y -= inc;
}
