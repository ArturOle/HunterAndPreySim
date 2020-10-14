#include "Bot.h"

void Bot::GoUp()
{
	y_position += 1;
}

void Bot::GoDown()
{
	y_position -= 1;
}

void Bot::GoLeft()
{
	x_position -= 1;
}

void Bot::GoRight()
{
	x_position += 1;
}

bool Bot::isAlive()
{
	return alive;
}
