#include "Bot.h"


float Bot::Up()
{
	return this->dot.getPosition().y + dot.getRadius();
}


float Bot::Down()
{
	return this->dot.getPosition().y - dot.getRadius();
}


float Bot::Left()
{
	return this->dot.getPosition().x - dot.getRadius();
}


float Bot::Right()
{
	return this->dot.getPosition().x + dot.getRadius();
}


void Bot::Update()
{
	dot.move(this->velocity);
	x_position = dot.getPosition().x;
	y_position = dot.getPosition().y;

	if (this->Down() < 0) 
	{
		velocity.y = dot_velocity;
	}
	else if (this->Up() > height) 
	{
		velocity.y = -dot_velocity;
	}

	if (this->Left() < 0)
	{
		velocity.x = dot_velocity;
	}
	else if (this->Right() > width)
	{
		velocity.x = -dot_velocity;
	}
}
