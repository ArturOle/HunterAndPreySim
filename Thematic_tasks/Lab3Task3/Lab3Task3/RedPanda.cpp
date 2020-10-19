#include "RedPanda.h"

RedPanda::RedPanda(int new_weight)
{
	weight = new_weight;
}

void RedPanda::Eat()
{
	std::cout << " Yummy Yummy :) " << std::endl;
}

void RedPanda::Jump()
{
	std::cout << " I jump bruh :3 " << std::endl;
}
