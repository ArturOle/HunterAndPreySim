#pragma once
#include "Bot.h"


class Herbivore : public Bot
{
	Movement* movement;
	bool run = false;
public:
	Herbivore(int x_in, int y_in) : Bot(x_in, y_in)
	{
		dot_velocity = 5.0f;
		dot.setFillColor(sf::Color::Green);
		movement = new Movement();
	}

	void Flee(float x_c, float y_c);  // Provide carnivore coordinates to behavior_h->Flee and change velocity
	void SeakFood(float x_f, float y_f);  // Provide food coordinates to behavior_h->Flee and change velocity

	template<typename T>
	void Decision(T storage);
	template<typename T>
	void SocialDistancing(T storage, Herbivore* diffrent_herbi);

	~Herbivore();
};


template<typename T>
inline void Herbivore::SocialDistancing(T storage, Herbivore* diffrent_herbi)
{
	sf::Vector2f move = behavior->Repulsion(x_position, y_position, diffrent_herbi->x_position, diffrent_herbi->y_position);
	
	float x_move = x_position - diffrent_herbi->x_position;
	float y_move = y_position - diffrent_herbi->y_position;
	x_position += move.x * x_move;
	y_position += move.y * y_move;
	diffrent_herbi->x_position -= move.x * x_move;
	diffrent_herbi->y_position -= move.y * y_move;
}


template<typename T>
inline void Herbivore::Decision(T storage)
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

		if (distance < 100)
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
