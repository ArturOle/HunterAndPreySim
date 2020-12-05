#pragma once
#include <ctime>

#include "Bot.h"
#include "Herbivore.h"


class Carnivore : public Bot
{
protected:
	const time_t max_life_time = 5;
	time_t birth_time;
	Behavior_C* behavior;

public:
	Carnivore(int x_in, int y_in) : Bot(x_in, y_in)
	{
		dot.setFillColor(sf::Color::Red);
		dot_velocity = 4.0f;
		birth_time = time(0);
		behavior = new Behavior_C();
	}

	char Type();

	void Hunt(Herbivore* herbi);  //Provide herbivore coordinates to behavior_h->Fleeand change velocity
	void AddTime();  // Adds 5 seconds after eating herbivore
	int CheckTime();  // Controls carnivores lifetime

	~Carnivore();
};

