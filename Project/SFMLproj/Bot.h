#pragma once
#include "Dot.h"


class Bot : public Dot
{
	bool alive;

public:
	
	Bot(float x_in, float y_in) :Dot(x_in, y_in) 
	{ 
		alive = true;
		std::cout << "Bot " << this << " is born!" << std::endl;
		dot.setFillColor(sf::Color::Blue);
	}

	void GoUp();
	void GoDown();
	void GoLeft();
	void GoRight();
	bool isAlive();
};

