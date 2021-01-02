#include "Behavior.h"


sf::Vector2f Behavior_H::Flee(float x_h_in, float y_h_in, float x_c_in, float y_c_in)
{
	float x_move = x_c_in - x_h_in;
	float y_move = y_c_in - y_h_in;

	float curr_distance_hunter = sqrtf(pow(x_move, 2) + pow(y_move, 2));
	sf::Vector2f directional_vector = { -x_move / curr_distance_hunter, -y_move / curr_distance_hunter };
	return directional_vector;
}


sf::Vector2f Behavior_H::Seek(float x_h_in, float y_h_in, float x_f_in, float y_f_in)
{
	float x_move = x_f_in - x_h_in;
	float y_move = y_f_in - y_h_in;

	float curr_distance_food = sqrtf(pow(x_move, 2) + pow(y_move, 2));
	sf::Vector2f directional_vector = { x_move / curr_distance_food, y_move / curr_distance_food };
	return directional_vector;
}


sf::Vector2f Behavior_C::KeepDistance(float x_h_in, float y_h_in, float x_c_in, float y_c_in)
{
	float x_move = x_c_in - x_h_in;
	float y_move = y_c_in - y_h_in;

	float curr_distance_hunter = sqrtf(pow(x_move, 2) + pow(y_move, 2));
	sf::Vector2f directional_vector = { -x_move / curr_distance_hunter, -y_move / curr_distance_hunter };
	return directional_vector;
}


sf::Vector2f Behavior_C::Hunt(float x_c_in, float y_c_in, float x_h_in, float y_h_in)
{
	float x_move = x_h_in - x_c_in;
	float y_move = y_h_in - y_c_in;

	float curr_distance_pray = sqrtf(pow(x_move, 2) + pow(y_move, 2));
	sf::Vector2f directional_vector = { x_move / curr_distance_pray, y_move / curr_distance_pray };
	return directional_vector;
}
