#pragma once
#include "Animal.h"

class Glonk : public Animal
{

public:
	Glonk(int new_weight);

	virtual void Eat();
	void Dies();
	void Nothing();
};

