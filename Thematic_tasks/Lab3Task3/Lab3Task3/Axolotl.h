#pragma once
#include "Animal.h"

class Axolotl : public Animal 
{
public:
	Axolotl(int new_weight);

	virtual void Eat();
	void Swim();
};

