#include "Obstacle.h"

void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(rect);
}