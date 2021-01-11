#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>


class Movement
{
public:
	sf::Vector2f Attraction(float x_first_in, float y_first_in, float x_second_in, float y_second_in);
	sf::Vector2f Repulsion(float x_first_in, float y_first_in, float x_second_in, float y_second_in);
};