#pragma once
#include "Bot.h"


class Carnivore : public Bot
{
public:
	Carnivore(int x_in, int y_in) : Bot(x_in, y_in)
	{
		dot.setFillColor(sf::Color::Red);
		dot_velocity = 4.0f;
	}

	void Atack();
};

