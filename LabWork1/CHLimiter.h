#pragma once
#include <Windows.h>
#include <Windowsx.h>

class CHLimiter
{
	int y;
	int xmin, xmax;

public:
	CHLimiter(int xmin, int xmax, int y);
	~CHLimiter();
	void Draw(HDC hdc);
	int GetMaxX();
	int GetMinX();
	int GetY();
	void MoveX(int inc);
	void MoveY(int inc);
};

