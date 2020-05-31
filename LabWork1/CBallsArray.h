#pragma once
#include <Windows.h>
#include <windowsx.h>
#include "CBall.h"
#include "CColoredBall.h"
#include "CBallsTimeLmited.h"
#include "Trap.h"
#include "wind.h"
#include <typeinfo>
class CBallsArray
{
	
	HWND HwndG;
	HWND Hwnd;
	int count;
	int count1;
	int max_balls;
	double gF;
	
public:
	CBall** balls;
	CBallsArray();
	CBallsArray(int max_balls);
	virtual ~CBallsArray(void);
	CBall* Add();
	void SetBounds(RECT bnds);
	void Move(DWORD ticks);
	void Draw(HDC hdc);
	CColoredBall* AddColoredBall();
	CBallsTimeLmited* AddLImitedBall();
	int GetCount() { return this->count; };
	int GetMaxCount() { return this->max_balls; };
	void SetCount(const int count) { this->count = count; };
	CBall * operator [] (const int index) { return this->balls[index]; };
	void SetGravityFactor(double gF, DWORD ticks);
	bool empty() { if (this->count == 0) return true; return false;};
	void SetTrap(Trap * t);
	void SetWind(wind * w);
	void del();
};

