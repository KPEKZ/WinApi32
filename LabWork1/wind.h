#pragma once
#include <Windows.h>
#include <Windowsx.h>
#include "CBall.h"
class wind
{
	HBRUSH hbrush;
	HPEN hpen;
	double angle;
	double speed;

public:
	wind();
	~wind();

	void Draw(HDC hdc);
	void SpeedUP();
	void SpeedDown();
	void AngleUp();
	void AngleDown();
	void GetVXVY(CBall *b);
};

