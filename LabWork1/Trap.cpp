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

	/*if (dist > r){
	}
		return;*/

	if (dist < this->r) {
		dist = this->r;
		//b->v_x *= -1;
		//b->v_y *= -1;
	}
		

	double x_factor = (F * (x_dist / dist)) / (dist2);
	double y_factor = (F * (y_dist / dist)) / (dist2);
	//b->v_x += x_factor;
	//b->v_y += y_factor;

	//if (dist < r) {
	//	dist = this->r;

	//	//if (dist2 <= ((b->r + this->r) * (b->r + this->r))) {

	//		double AC_scalar = b->v_x * x_dist + b->v_y * y_dist;
	//		//double BC_scalar = ball2->v_x * C_x + ball2->v_y * C_y;

	//		double Ap_v_x = (x_dist * AC_scalar) / dist2;
	//		double Ap_v_y = (y_dist * AC_scalar) / dist2;
	//		double At_v_x = b->v_x - Ap_v_x;
	//		double At_v_y = b->v_x - Ap_v_y;

	//		/*double Bp_v_x = (C_x * BC_scalar) / c2;
	//		double Bp_v_y = (C_y * BC_scalar) / c2;
	//		double Bt_v_x = ball2->v_x - Bp_v_x;
	//		double Bt_v_y = ball2->v_x - Bp_v_y;*/

	//		b->v_x = /*Bp_v_x*/  At_v_x + x_factor;
	//		b->v_y = /*Bp_v_y*/  At_v_y + y_factor;
	//		/*ball2->v_x = Ap_v_x + Bt_v_x;
	//		ball2->v_y = Ap_v_y + Bt_v_y;*/

	//	//}
	//}


}

Trap::~Trap(void)
{
}
