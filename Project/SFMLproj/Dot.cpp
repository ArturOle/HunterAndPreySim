#include "Dot.h"


Dot::Dot(float x_in, float y_in)
{

	dot.setPosition(x_in, y_in);
	dot.setRadius(radius);
	dot.setOrigin(this->radius, this->radius);
	dot.setFillColor(sf::Color::White);
}


void Dot::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(dot);
}




/*
void Dot::Draw()
{
	parent->AddDrawing(dot);
}

*/