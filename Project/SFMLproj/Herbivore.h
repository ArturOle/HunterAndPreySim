#pragma once
#include "Bot.h"


class Herbivore : public Bot
{
	Behavior_H* behavior;
	bool run = false;
public:
	Herbivore(int x_in, int y_in) : Bot(x_in, y_in)
	{
		dot.setFillColor(sf::Color::Green);
		behavior = new Behavior_H();
	}

	void Flee(float x_c, float y_c);  // Provide carnivore coordinates to behavior_h->Flee and change velocity
	void SeakFood(float x_f, float y_f);  // Provide food coordinates to behavior_h->Flee and change velocity

	template<typename T1>
	void Decision(T1 storage);

	~Herbivore();
};


template<typename T1>
inline void Herbivore::Decision(T1 storage)
{
	float distance, shortest_distance;
	shortest_distance = INFINITY;

	for (auto& y : storage->foods)
	{
		if (run == false)
		{
			distance = storage->CalcDistance(this->x_position, this->y_position, y->x_position, y->y_position);

			if (shortest_distance > distance)
			{
				shortest_distance = distance;
				SeakFood(y->x_position, y->y_position);
			}
		}
	}

	for (auto& y : storage->carni)
	{
		distance = storage->CalcDistance(this->x_position, this->y_position, y->x_position, y->y_position);

		if (100 > distance)
		{
			Flee(y->x_position, y->y_position);
			run = true;
		}
		else
		{
			run = false;
		}
	}
}
