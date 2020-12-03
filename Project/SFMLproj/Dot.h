#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Dot : public sf::Drawable
{
protected:
	sf::CircleShape dot;
	sf::RenderTarget* target;
	float radius = 10;
	float x_position;
	float y_position;

	friend class Window;

public:

	Dot(float x_in, float y_in);
	Dot() = delete;

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	~Dot() = default;

};

