#include "Carnivore.h"


char Carnivore::Type()
{
	return 'c';
}


void Carnivore::Hunt(float x_h, float y_h)
{
	this->velocity = behavior->Hunt(x_h, y_h);
}


void Carnivore::AddTime()
{
	birth_time = birth_time + 10;
}


int Carnivore::CheckTime()
{
	return time(0) - (birth_time + max_life_time);
}


Carnivore::~Carnivore()
{
	delete behavior;
}
