#pragma once
#include "Drink.h"
#include <string>

class Juice : public Drink
{
	std::string flavor;
public:
	Juice();
	Juice(std::string set_flavor);
	
};

