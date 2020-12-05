#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>


class Behavior_H
{
public:

	sf::Vector2f Flee(float x_h_in, float y_h_in, float x_c_in, float y_c_in);
	sf::Vector2f Seek(float x_h_in, float y_h_in, float x_f_in, float y_f_in);
};


class Behavior_C 
{
public:

	sf::Vector2f Hunt(float x_c_in, float y_c_in, float x_h_in, float y_h_in);
};
