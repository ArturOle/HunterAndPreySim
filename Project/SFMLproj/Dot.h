#pragma once
#include <SFML/Graphics.hpp>


class Dot : private sf::Drawable
{
public:
	Dot(float x_in, float y_in);
	Dot() = delete;
	~Dot() = default;

private:
	friend class Window;
	sf::CircleShape dot;
	float radius = 10;
};

