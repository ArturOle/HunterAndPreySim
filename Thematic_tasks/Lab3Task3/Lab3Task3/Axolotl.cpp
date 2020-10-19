#include "Axolotl.h"

Axolotl::Axolotl(int new_weight)
{
	weight = new_weight;
}

void Axolotl::Eat()
{
	std::cout << " Yummy Yummy :) " << std::endl;
}

void Axolotl::Swim()
{
	std::cout << " I swim, sometimes :> " << std::endl;
}
