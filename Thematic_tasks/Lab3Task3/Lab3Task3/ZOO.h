#pragma once
#include <random>
#include <vector>
#include "Animal.h"
#include "Axolotl.h"
#include "Glonk.h"
#include "RedPanda.h"

class ZOO
{
	int quantity;
public:
	std::vector<Animal*> censos;

	ZOO(int quantity);

	int randint(int from, int to);

	~ZOO();
};

