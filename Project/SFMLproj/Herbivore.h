#pragma once
#include "Bot.h"


class Herbivore : public Bot
{
	Behavior_H* behavior;
public:
	Herbivore(int x_in, int y_in) : Bot(x_in, y_in)
	{
		dot.setFillColor(sf::Color::Green);
		behavior = new Behavior_H();
	}

	char Type();

	void Flee(float x_c, float y_c);  // Provide carnivore coordinates to behavior_h->Flee and change velocity
	void SeakFood(float x_f, float y_f);  // Provide food coordinates to behavior_h->Flee and change velocity

	~Herbivore();
};

