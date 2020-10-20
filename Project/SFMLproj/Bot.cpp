#include "Bot.h"


float Bot::GoUp()
{
	return this->dot.getPosition().y + dot.getRadius();
}


float Bot::GoDown()
{
	return this->dot.getPosition().y - dot.getRadius();
}


float Bot::GoLeft()
{
	return this->dot.getPosition().x - dot.getRadius();
}


float Bot::GoRight()
{
	return this->dot.getPosition().x + dot.getRadius();
}


void Bot::Update()
{
	dot.move(this->velocity);

	if (this->GoDown() < 0) 
	{
		velocity.y = dot_velocity;
	}
	else if (this->GoUp() > height) 
	{
		velocity.y = -dot_velocity;
	}

	if (this->GoLeft() < 0)
	{
		velocity.x = dot_velocity;
	}
	else if (this->GoRight() > width)
	{
		velocity.x = -dot_velocity;
	}
}


bool Bot::isAlive()
{
	return alive;
}
