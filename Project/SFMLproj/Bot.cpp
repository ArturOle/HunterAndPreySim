#include "Bot.h"


char Bot::Type()
{
	return 'b';
}


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


void Bot::CurrentMovement(int move_x, int move_y)
{
	this->velocity.x = dot_velocity * move_x;
	this->velocity.y = dot_velocity * move_y;
}


int Bot::randint(int from, int to)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(from, to);
	int pseudorandom_number = dist(mt);
	return pseudorandom_number;
}


void Bot::Update()
{
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

	dot.move(this->velocity);
	x_position = dot.getPosition().x;
	y_position = dot.getPosition().y;
}
