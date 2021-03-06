#include "Dot.h"


Dot::Dot(float x_in, float y_in)
{
	x_position = x_in;
	y_position = y_in;
	dot.setPosition(x_position, y_position);
	dot.setRadius(radius);
	dot.setOrigin(this->radius, this->radius);
}


void Dot::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(dot);
}
