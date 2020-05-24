#pragma once
#include "CBall.h"
#define _USE_MATH_DEFINES
#include <math.h>



class Trap
{
public:
	Trap();
	double x, y;
	double F;
	double r;
	void SetParams (double x, double y, double F, double r);
	virtual void Draw(HDC hdc);
	void MoveBall(CBall* b);
	virtual ~Trap(void);
	
};

