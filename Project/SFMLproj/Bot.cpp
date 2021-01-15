#include "Bot.h"


float Bot::Up()
{
	return this->dot.getPosition().y + dot.getRadius();
}


float Bot::Down()
{
	return this->dot.getPosition().y - dot.getRadius();
}


float Bot::Left()
{
	return this->dot.getPosition().x - dot.getRadius();
}


float Bot::Right()
{
	return this->dot.getPosition().x + dot.getRadius();
}
