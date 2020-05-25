#include "wind.h"
#define _USE_MATH_DEFINES
#include <math.h>

wind::wind()
{
	this->hbrush = CreateSolidBrush(RGB(255, 255, 255));
	//this->F = 9.0;
	this->angle = 45.0;
	this->speed = 0.0;
}

wind::~wind()
{
	DeleteBrush(this->hbrush);
	DeleteObject(this->hpen);
}

void wind::Draw(HDC hdc)
{
	//hbrush = CreateSolidBrush(RGB(255, 0, 0));
	SelectBrush(hdc, hbrush);
	hpen = CreatePen(PS_SOLID, 1, RGB(6, 55, 179));
	SelectObject(hdc, hpen);
	double halfspeed = ((this->speed / 120) * 30) / 2;
	double rad_angle = (this->angle / 180) * M_PI;
	double x = halfspeed * cos(rad_angle);
	double y = halfspeed * sin(rad_angle);
	Rectangle(hdc, 31, 0, 61, 30);
	MoveToEx(hdc, 46 - x, 15 - y, NULL);
	LineTo(hdc, 46 + x, 15 + y);
	Ellipse(hdc, 46 + x - 2, 15 + y - 2, 46 + x + 2, 15 + y + 2);
	//DeleteObject(hpen);
	//DeleteBrush(hbrush);
}

void wind::SpeedUP()
{
	if (this->speed < 120)
		speed++;

}

void wind::SpeedDown()
{
	if (this->speed > 10)
		speed--;
}

void wind::AngleUp()
{
	angle++;
	if (angle >= 360)
		angle = 0;
}

void wind::AngleDown()
{
	angle--;
	if (angle < 0)
		angle = 360;
}

void wind::GetVXVY(CBall *b)
{
	double rad_angle = (this->angle / 180) * M_PI;
	b->v_x += this->speed * cos(rad_angle);
	b->v_y += this->speed * sin(rad_angle);

}