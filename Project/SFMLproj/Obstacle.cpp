#include "Obstacle.h"


Obstacle::Obstacle(int a_in, int b_in, float x_position_in, float y_position_in)
{
	a = a_in;
	b = b_in;
	x_position = x_position_in;
	y_position = y_position_in;
	rect.setPosition(x_position, y_position);
	rect.setSize(sf::Vector2f(a, b));
	rect.setFillColor(sf::Color(255, 255, 255, 100));
}


float Obstacle::bound_left()
{
	return x_position;
}


float Obstacle::bound_right()
{
	return x_position + a;
}


float Obstacle::bound_top()
{
	return y_position;
}


float Obstacle::bound_bottom()
{
	return y_position + b;
}


void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(rect);
}