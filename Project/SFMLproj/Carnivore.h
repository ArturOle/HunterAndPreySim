#pragma once
#include <ctime>

#include "Bot.h"


class Carnivore : public Bot
{
protected:
	const time_t max_life_time = 10;
	time_t birth_time;
public:
	Carnivore(int x_in, int y_in) : Bot(x_in, y_in)
	{
		dot.setFillColor(sf::Color::Red);
		dot_velocity = 4.0f;
		birth_time = time(0);
	}

	void Atack();
	void AddTime();
	int CheckTime();
};

