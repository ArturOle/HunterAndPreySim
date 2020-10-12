#include "Drink.h"


void Drink::consume()
{
	std::cout << "Consumed" << std::endl;

}

Drink::Drink()
{
	std::cout << "have your drink bruh" << std::endl;
}

Drink::Drink(float height_in, float width_in)
{
	std::cout << "have your drink bruh, its " << height_in << "per" << width_in << std::endl;
	height = height_in;
	width = width_in;
}
