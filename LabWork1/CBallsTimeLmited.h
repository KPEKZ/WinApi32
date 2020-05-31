#pragma once
#include "CBall.h"
class CBallsTimeLmited :
	public CBall
{

	HBRUSH hbrush;
	HDC hdc;
	HWND hwnd;

public:
	CBallsTimeLmited();
	virtual ~CBallsTimeLmited();
	virtual void SetColor(unsigned char r, unsigned char g, unsigned char b) override;
	virtual void Draw(HDC hdc) override;
	virtual bool GetType() { return true; };
	/*void SetHWND(HWND hwnd);*/
};

