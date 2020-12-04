#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>


class Behavior_H
{
	float x_h, y_h;
public:
	Behavior_H(float x_h_in, float y_h_in);

	sf::Vector2f Flee(float x_c_in, float y_c_in);
	sf::Vector2f Seek(float x_f_in, float y_f_in);
};


class Behavior_C 
{
	float x_c, y_c;
public:
	Behavior_C(float x_c_in, float y_c_in);

	sf::Vector2f Hunt(float x_h_in, float y_h_in);
};
