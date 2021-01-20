#pragma once
#include "Dot.h"
#include "Movement.h"


#define height 800
#define width 1000


class Bot : public Dot
{
protected:
	bool alive = true;
	float dot_velocity = 5.0f;
	sf::Vector2f velocity;

public:
	
	Bot(float x_in, float y_in) :Dot(x_in, y_in) 
	{ 
		//std::cout << "Bot " << this << " is born!" << std::endl;
		dot.setFillColor(sf::Color::Blue);
	}

	float Up();  // Caclulates higher boundry of a dot
	float Down();  // Lower boundry
	float Left();  // Left boundry
	float Right();  // Right boundry

	template<typename T>
	void Update(T storage);  // Updates data od the dot, checks border collisions and changes velocity respectively
};


template<typename T>
inline void Bot::Update(T storage)
{
	if (this->Down() <= 0)
	{
		velocity.y = dot_velocity;
	}
	else if (this->Up() >= height)
	{
		velocity.y = -dot_velocity;
	}

	if (this->Left() <= 0)
	{
		velocity.x = dot_velocity;
	}
	else if (this->Right() >= width)
	{
		velocity.x = -dot_velocity;
	}

	if (storage->IsIntersecting(this, storage->obstacles[0]))
	{
		if (this->Left() <= storage->obstacles[0]->bound_right())
		{
			velocity.x = dot_velocity;
		}
		else if (this->Right() >= storage->obstacles[0]->bound_left())
		{
			velocity.x = -dot_velocity;
		}

		if (this->Up() >= storage->obstacles[0]->bound_bottom())
		{
			velocity.y = dot_velocity;
		}
		else if (this->Down() <= storage->obstacles[0]->bound_top())
		{
			velocity.y = -dot_velocity;
		}
		if (this->Right() >= storage->obstacles[0]->bound_left())
		{
			velocity.x = -dot_velocity;
		}
	}

	dot.move(this->velocity);
	x_position = dot.getPosition().x;
	y_position = dot.getPosition().y;
}