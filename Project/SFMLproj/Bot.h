#pragma once
#include "Dot.h"
#include "Behavior.h"


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

	char Type();  // Returns code type of this object, 'b' 

	float Up();  // Caclulates higher boundry of a dot
	float Down();  // Lower boundry
	float Left();  // Left boundry
	float Right();  // Right boundry

	void Update();  // Updates data od the dot, checks border collisions and changes velocity respectively
};

