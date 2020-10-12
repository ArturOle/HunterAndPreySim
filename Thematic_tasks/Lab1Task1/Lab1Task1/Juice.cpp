#include "Juice.h"

Juice::Juice()
{
	std::cout << "Juice without the flavor" << std::endl;
}

Juice::Juice(std::string set_flavor)
{
	std::cout << "Drink with flavor " << set_flavor << std::endl;
}

