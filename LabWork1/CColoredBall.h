#pragma once
#include "CBall.h"
class CColoredBall :
	public CBall
{

	HBRUSH hBrush;

public:
	CColoredBall();
	virtual ~CColoredBall();
	virtual void SetColor(unsigned char r, unsigned char g, unsigned char b) override;
	virtual void Draw(HDC hdc) override;
};

