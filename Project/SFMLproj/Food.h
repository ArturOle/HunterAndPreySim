#pragma once
#include "Dot.h"
#include "Window.h"


class Food : public Dot
{
	bool alive = true;
public:
	Food(int x_in, int y_in) : Dot(x_in, y_in)
	{
		dot.setFillColor(sf::Color::Yellow);
	}

	char Type();
};

