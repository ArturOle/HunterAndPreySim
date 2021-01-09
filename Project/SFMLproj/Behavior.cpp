#include "Behavior.h"


sf::Vector2f Behavior::Repulsion(float x_first_in, float y_first_in, float x_second_in, float y_second_in)
{
	float x_move = x_second_in - x_first_in;
	float y_move = y_second_in - y_first_in;

	float current_distance_hunter = sqrtf(pow(x_move, 2) + pow(y_move, 2));

	sf::Vector2f directional_vector = { -x_move / current_distance_hunter,
										-y_move / current_distance_hunter };

	return directional_vector;
}


sf::Vector2f Behavior::Attraction(float x_first_in, float y_first_in, float x_second_in, float y_second_in)
{
	float x_move = x_second_in - x_first_in;
	float y_move = y_second_in - y_first_in;

	float current_distance_food = sqrtf(pow(x_move, 2) + pow(y_move, 2));

	sf::Vector2f directional_vector = { x_move / current_distance_food,y_move / current_distance_food };

	return directional_vector;
}