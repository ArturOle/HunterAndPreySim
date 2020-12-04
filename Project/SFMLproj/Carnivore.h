#pragma once
#include <ctime>

#include "Bot.h"


class Carnivore : public Bot
{
protected:
	const time_t max_life_time = 100;
	time_t birth_time;
	Behavior_C* behavior;

public:
	Carnivore(int x_in, int y_in) : Bot(x_in, y_in)
	{
		dot.setFillColor(sf::Color::Red);
		dot_velocity = 4.0f;
		birth_time = time(0);
		behavior = new Behavior_C(x_in, y_in);
	}

	char Type();

	void Hunt(float x_f, float y_f);
	void AddTime();
	int CheckTime();

	~Carnivore();
};

