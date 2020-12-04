#include "Behavior.h"


Behavior_H::Behavior_H(float x_h_in, float y_h_in)
{
	x_h = x_h_in;
	y_h = y_h_in;
}


sf::Vector2f Behavior_H::Flee(float x_c_in, float y_c_in)
{
	float x_move = x_h - x_c_in;
	float y_move = y_h - y_c_in;

	float curr_distance_hunter = sqrtf(pow(x_move, 2) + pow(y_move, 2));
	sf::Vector2f directional_vector = { 3*x_move / curr_distance_hunter, 3*y_move / curr_distance_hunter };
	return directional_vector;
}


sf::Vector2f Behavior_H::Seek(float x_f_in, float y_f_in)
{
	float x_move = x_h - x_f_in;
	float y_move = y_h - y_f_in;

	float curr_distance_food = sqrtf(pow(x_move, 2) + pow(y_move, 2));
	sf::Vector2f directional_vector = { -3*x_move / curr_distance_food, -3*y_move / curr_distance_food };
	return directional_vector;
}


Behavior_C::Behavior_C(float x_c_in, float y_c_in)
{
	x_c = x_c_in;
	y_c = y_c_in;
}


sf::Vector2f Behavior_C::Hunt(float x_h_in, float y_h_in)
{
	float x_move = x_c - x_h_in;
	float y_move = y_c - y_h_in;

	float curr_distance_pray = sqrtf(pow(x_move, 2) + pow(y_move, 2));
	sf::Vector2f directional_vector = { -4*x_move / curr_distance_pray, -4*y_move / curr_distance_pray };
	return directional_vector;
}
