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

	template<typename T>
	void Decision(T storage);

	~Carnivore();
};

template<typename T>
inline void Carnivore::Decision(T storage)
{
	float shortest_distance, distance;
	shortest_distance = INFINITY;

	for (auto& y : storage->herbi)
	{
		distance = storage->CalcDistance(this->x_position, this->y_position, y->x_position, y->y_position);

		if (distance < shortest_distance)
		{
			shortest_distance = distance;
			this->Hunt(y);
		}
	}
}
