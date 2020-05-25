#include "CBallsArray.h"

CBallsArray::CBallsArray(int max_balls) 
{
	this->gF = 0;
	this->max_balls = max_balls;
	this->count = 0;
	this->balls = new CBall * [max_balls];
	this->trap = new Trap();
}

CBallsArray::~CBallsArray(void)
{
	for (int i{ 0 }; i < count; i++) {
		delete this->balls[i];
	}

	delete[] this->balls;
	delete this->trap;
}

CBall* CBallsArray::Add()
{

	if (count >= this->max_balls)
		return NULL;

	count++;
	return balls[count - 1] = new CBall();
	
}

void CBallsArray::SetBounds(RECT bnds)
{
	for (int i{ 0 }; i < count; i++) {
		balls[i]->SetBounds(bnds);
	}
}

void CBallsArray::Move(DWORD ticks)
{
	CBall* ball1;
	CBall* ball2;

	for (int i{ 0 }; i < count; i++) {
		for (int j{ i + 1 }; j < count; j++) {
			
			ball1 = this->balls[i];
			ball2 = this->balls[j];

			double C_x = ball2->x - ball1->x;
			double C_y = ball2->y - ball1->y;
			double c2 = C_x * C_x + C_y * C_y;

			if (c2 <= ((ball1->r + ball2->r) * (ball1->r + ball2->r))) {
				
				double AC_scalar = ball1->v_x * C_x + ball1->v_y * C_y;
				double BC_scalar = ball2->v_x * C_x + ball2->v_y * C_y;

				double Ap_v_x = (C_x * AC_scalar) / c2;
				double Ap_v_y = (C_y * AC_scalar) / c2;
				double At_v_x = ball1->v_x - Ap_v_x;
				double At_v_y = ball1->v_x - Ap_v_y;

				double Bp_v_x = (C_x * BC_scalar) / c2;
				double Bp_v_y = (C_y * BC_scalar) / c2;
				double Bt_v_x = ball2->v_x - Bp_v_x;
				double Bt_v_y = ball2->v_x - Bp_v_y;

				ball1->v_x = Bp_v_x + At_v_x;
				ball1->v_y = Bp_v_y + At_v_y;
				ball2->v_x = Ap_v_x + Bt_v_x;
				ball2->v_y = Ap_v_y + Bt_v_y;

			}

			//double CC_x = trap->x - ball1->x;
			//double CC_y = trap->y - ball1->y;
			//double cc2 = C_x * C_x + C_y * C_y;

			//if (cc2 <= ((ball1->r + trap->r) * (ball1->r + trap->r)))
			//{
			//	double AC_scalar = ball1->v_x * CC_x + ball1->v_y * CC_y;
			//	double BC_scalar = ball2->v_x * CC_x + ball2->v_y * CC_y;

			//	double Ap_v_x = (CC_x * AC_scalar) / cc2;
			//	double Ap_v_y = (CC_y * AC_scalar) / cc2;
			//	double At_v_x = ball1->v_x - Ap_v_x;
			//	double At_v_y = ball1->v_x - Ap_v_y;

			//	double Bp_v_x = (CC_x * BC_scalar) / cc2;
			//	double Bp_v_y = (CC_y * BC_scalar) / cc2;
			//	//double Bt_v_x = ball2->v_x - Bp_v_x;
			//	//double Bt_v_y = ball2->v_x - Bp_v_y;

			//	ball1->v_x = Bp_v_x + At_v_x;
			//	ball1->v_y = Bp_v_y + At_v_y;
			//	
			//}

		}
	}

	for (int i{ 0 }; i < count; i++) {
		balls[i]->Move(ticks);
	}
}

void CBallsArray::Draw(HDC hdc)
{
	for (int i{ 0 }; i < count; i++) {
		balls[i]->Draw(hdc);
	}
	this->trap->Draw(hdc);
}

CColoredBall* CBallsArray::AddColoredBall()
{
	if (count >= max_balls)
		return NULL;
	count++;
	balls[count - 1] = new CColoredBall();
	return (CColoredBall *)balls[count - 1];

	
}

CBallsTimeLmited* CBallsArray::AddLImitedBall()
{
	if (count >= max_balls)
		return NULL;
	count++;
	balls[count - 1] = new CBallsTimeLmited();
	return (CBallsTimeLmited*)balls[count - 1];
	
}

void CBallsArray::SetGravityFactor(double gF, DWORD ticks)
{
	this->gF = gF;
	for (size_t i{ 0 }; i < this->count; i++) {
		balls[i]->v_y += this->gF;
	}

	for (size_t i{ 0 }; i < this->count; i++) {
		balls[i]->Move(ticks);
	}
}

void CBallsArray::SetTrap()
{
	 trap->SetParams(200, 200, 20000.0, 50);
	for (size_t i{ 0 }; i < this->count; i++) {
		trap->MoveBall(balls[i]);
	}
}

void CBallsArray::SetWind(wind* w)
{
	for (size_t i{ 0 }; i < this->count; i++) {
		w->GetVXVY(balls[i]);
	}

}


