#include "Behavior.h"

Behavior_H::Behavior_H(float x_h_in, float y_h_in)
{
	x_h = x_h_in;
	y_h = y_h_in;
}

void Behavior_H::Flee(float x_c_in, float y_c_in)
{
	float x_move = x_h - x_c_in;
	float y_move = y_h - y_c_in;

	this->curr_distance_hunter = sqrtf(pow(x_move, 2) + pow(y_move, 2));
}

void Behavior_H::Seek(float x_f_in, float y_f_in)
{
}

Behavior_C::Behavior_C(float x_c_in, float y_c_in)
{
	x_c = x_c_in;
	y_c = y_c_in;
}

void Behavior_C::Hunt(float x_h_in, float y_h_in)
{
}
