#include "Obstacle.h"


Obstacle::Obstacle(int a, int b, float x_position_in, float y_position_in)
{
	x_position = x_position_in;
	y_position = y_position_in;
	rect.setPosition(x_position, y_position);
	rect.setSize(sf::Vector2f(a, b));
}

void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(rect);
}