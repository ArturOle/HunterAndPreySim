#include "Glonk.h"

Glonk::Glonk(int new_weight)
{
	weight = new_weight;
}

void Glonk::Eat()
{
	std::cout << " *Burp*, I eat :O " << std::endl;
}

void Glonk::Dies()
{
	std::cout << " *Burp* I die :3 " << std::endl;
}

void Glonk::Nothing()
{
	std::cout << " *Burp* " << std::endl;
}
