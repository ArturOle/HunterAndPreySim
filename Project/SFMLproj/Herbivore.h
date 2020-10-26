#pragma once
#include "Bot.h"


class Herbivore : public Bot
{
public:
	Herbivore(int x_in, int y_in) : Bot(x_in, y_in)
	{
		dot.setFillColor(sf::Color::Green);
	}

	void Flee();
	void SeakFood();

};

