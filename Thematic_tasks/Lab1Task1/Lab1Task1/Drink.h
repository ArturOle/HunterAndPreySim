#pragma once
#include <iostream>


class Drink
{
	float height = 0;
	float width = 0;
	
public:
	void consume();
	Drink();
	Drink(float height_in, float width_in);

};

