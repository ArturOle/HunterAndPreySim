#include "Herbivore.h"


char Herbivore::Type()
{
	return 'h';
}


void Herbivore::Flee(float x_c, float y_c)
{
	this->velocity = behavior->Flee(x_position, y_position, x_c, y_c);
}


void Herbivore::SeakFood(float x_f, float y_f)
{
	this->velocity = behavior->Seek(x_position, y_position, x_f, y_f);
}


Herbivore::~Herbivore()
{
	delete behavior;
}
