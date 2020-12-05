#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>


class Behavior_H  // behavior for herbivore
{
public:

	sf::Vector2f Flee(float x_h_in, float y_h_in, float x_c_in, float y_c_in);  // Calculates distance and move for fleeing
	sf::Vector2f Seek(float x_h_in, float y_h_in, float x_f_in, float y_f_in);  // Calculates distance and move to eat
};


class Behavior_C  // behavior for carnivore
{
public:

	sf::Vector2f Hunt(float x_c_in, float y_c_in, float x_h_in, float y_h_in);  // Calculates distance and move to hunt down herbivore
};
