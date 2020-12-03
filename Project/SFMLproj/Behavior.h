#pragma once
#include <math.h>


class Behavior_H
{
	float curr_distance_food;
	float curr_distance_hunter;
	float x_h, y_h;
public:
	Behavior_H(float x_h_in, float y_h_in);

	void Flee(float x_c_in, float y_c_in);
	void Seek(float x_f_in, float y_f_in);
};


class Behavior_C 
{
	float curr_distance_pray;
	float x_c, y_c;
public:
	Behavior_C(float x_c_in, float y_c_in);

	void Hunt(float x_h_in, float y_h_in);
};
