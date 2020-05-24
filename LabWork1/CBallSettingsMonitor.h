#pragma once
#include <Windows.h>

class CBallSettingsMonitor
{
	double angle;
	double speed;
	double R;
	int T;

public:
	CBallSettingsMonitor();
	~CBallSettingsMonitor();

	void Draw(HDC hdc);
	void SpeedUP();
	void SpeedDown();
	void AngleUp();
	void AngleDown();
	void GetVXVY(double& v_x, double& v_y);
};

