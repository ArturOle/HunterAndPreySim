#include "Carnivore.h"


char Carnivore::Type()
{
	return 'c';
}


void Carnivore::Hunt(Herbivore* herbi)
{
	this->velocity.x = 0;
	this->velocity.y = 0;
	this->velocity = behavior->Hunt(x_position, y_position, herbi->x_position, herbi->y_position);
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
	delete behavior;
}
