#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Dot : public sf::Drawable
{
protected:
	sf::CircleShape dot;
	sf::RenderTarget* target;  // Where dot will be drawn
	float radius = 5;
	friend class Storage;
	friend class Window;

public:
	float x_position;
	float y_position;

	Dot(float x_in, float y_in);
	Dot() = delete;

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;  // overriding base class method draw to target Window and draw dot

	~Dot() = default;
};

