#pragma once
#include "Dot.h"
#include "Behavior.h"

#include <random>

#define height 600
#define width 800

class Bot : public Dot
{
protected:
	bool alive;
	float dot_velocity = 3.0f;

private:
	sf::Vector2f velocity{ 0, 0 };

public:
	
	Bot(float x_in, float y_in) :Dot(x_in, y_in) 
	{ 
		alive = true;
		std::cout << "Bot " << this << " is born!" << std::endl;
		dot.setFillColor(sf::Color::Blue);
	}

	float Up();
	float Down();
	float Left();
	float Right();

	void CurrentMovement(int move_x, int move_y);
	int randint(int from, int to);
	void Update(int move_x, int move_y);
};

