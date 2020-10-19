#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Dot : public sf::Drawable
{
protected:
	sf::CircleShape dot;
	float radius = 10;
	float x_position;
	float y_position;

	friend class Window;
	//friend class Bot;

public:

	Dot(float x_in, float y_in);
	Dot() = delete;

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	~Dot() = default;

};

