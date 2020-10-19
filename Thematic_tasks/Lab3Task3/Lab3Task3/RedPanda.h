#pragma once
#include "Animal.h"

class RedPanda : public Animal
{
public:
	RedPanda(int new_weight);

	virtual void Eat();
	void Jump();
};

