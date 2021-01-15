#include "Carnivore.h"


void Carnivore::Hunt(Herbivore* herbi)
{
	this->velocity.x = 0;
	this->velocity.y = 0;
	this->velocity = this->dot_velocity*movement->Attraction(x_position, y_position, herbi->x_position, herbi->y_position);
}


void Carnivore::AddTime()
{
	birth_time = birth_time + 5;
}


int Carnivore::CheckTime()
{
	return time(0) - (birth_time + max_life_time);
}


Carnivore::~Carnivore()
{
	delete movement;
}
