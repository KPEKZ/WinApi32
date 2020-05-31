#pragma once
#include <Windows.h>
#include <Windowsx.h>
#include "CHLimiter.h"

class CBall
{
public:
	double x, y;
	double r;
	double v_x, v_y;
	RECT rect;
	bool timeLimit{ false };
	
	CBall();
	virtual ~CBall();
	 void SetParams(double x, double y, double r, double v_x, double v_y);
	virtual void Draw(HDC hdc);
	void SetBounds(RECT bnds);
	void Move(DWORD delta_ticks);
	virtual void SetColor(unsigned char r, unsigned char g, unsigned char b);
	virtual bool GetType() { return this->timeLimit; };
};

