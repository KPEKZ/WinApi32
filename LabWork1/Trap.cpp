#include "Trap.h"

Trap::Trap()
{
	
	this->x = 0;
	this->y = 0;
	this->F = 0;
	this->r = 0;
}

void Trap::SetParams(double x, double y, double F, double r)
{
	this->x = x;
	this->y = y;
	this->F = F;
	this->r = r;
}

void Trap::Draw(HDC hdc)
{
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc,pen);
	Ellipse(hdc, this->x, this->y, this->x+this->r, this->y + this->r);
}

void Trap::MoveBall(CBall* b)
{
	double x_dist = (this->x+ r) - (b->x+ b->r);
	double y_dist = (this->y + r) - (b->y + b->r);
	double x2_dist = x_dist*x_dist;
	double y2_dist = y_dist*y_dist;
	double dist2 = x2_dist + y2_dist;
	double dist = sqrt(dist2);

	if (dist > r){
		return;
	}
		

	if (dist2 < this->r) {
		dist2 = this->r;
		
	}
		

	double x_factor = (F * (x_dist / dist)) / (dist2);
	double y_factor = (F * (y_dist / dist)) / (dist2);
	b->v_x += x_factor;
	b->v_y += y_factor;

}

Trap::~Trap(void)
{
}
