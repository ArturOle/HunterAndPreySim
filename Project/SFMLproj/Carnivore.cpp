#include "Carnivore.h"

void Carnivore::Atack()
{

}

void Carnivore::AddTime()
{
	birth_time = birth_time + 10;
}

int Carnivore::CheckTime()
{
	return time(0) - (birth_time + max_life_time);
}
