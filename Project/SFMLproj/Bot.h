#pragma once
#include "Dot.h"
#include "Behavior.h"

#define height 600
#define width 800

class Bot : public Dot
{
protected:
	bool alive;
	float dot_velocity = 3.0f;

private:
	sf::Vector2f velocity{ dot_velocity, dot_velocity };

public:
	
	Bot(float x_in, float y_in) :Dot(x_in, y_in) 
	{ 
		alive = true;
		std::cout << "Bot " << this << " is born!" << std::endl;
		dot.setFillColor(sf::Color::Blue);
	}
	
	float GoUp();
	float GoDown();
	float GoLeft();
	float GoRight();
	void Update();
	void Death();
};

