#include "CBallSettingsMonitor.h"
#define _USE_MATH_DEFINES
#include <math.h>

CBallSettingsMonitor::CBallSettingsMonitor()
{
	this->angle = 45.0;
	this->speed = 50.0;
}

CBallSettingsMonitor::~CBallSettingsMonitor()
{

}

void CBallSettingsMonitor::Draw(HDC hdc)
{
	double halfspeed = ((this->speed / 120) * 30) / 2;
	double rad_angle = (this->angle / 180) * M_PI;
	double x = halfspeed * cos(rad_angle);
	double y = halfspeed * sin(rad_angle);
	Rectangle(hdc, 0 ,0, 30, 30);
	MoveToEx(hdc, 15 - x, 15 - y, NULL);
	LineTo(hdc, 15 + x, 15 + y);
	Ellipse(hdc, 15 + x - 2, 15 + y - 2, 15 + x + 2, 15 + y + 2);
}

void CBallSettingsMonitor::SpeedUP()
{
	if (this->speed < 120)
		speed++;

}

void CBallSettingsMonitor::SpeedDown()
{
	if (this->speed > 10)
		speed--;
}

void CBallSettingsMonitor::AngleUp()
{
	angle++;
	if (angle >= 360)
		angle = 0;
}

void CBallSettingsMonitor::AngleDown()
{
	angle--;
	if (angle < 0)
		angle = 360;
}

void CBallSettingsMonitor::GetVXVY(double& v_x, double& v_y)
{
	double rad_angle = (this->angle / 180) * M_PI;
	v_x = this->speed * cos(rad_angle);
	v_y = this->speed * sin(rad_angle);
}
