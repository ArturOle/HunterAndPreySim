#pragma once
#include <SFML/Graphics.hpp>


class Dot : public sf::Drawable
{
private:
	sf::CircleShape dot;
	float radius = 10;

public:
	Dot(float x_in, float y_in);
	Dot() = delete;
	

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	~Dot() = default;


};

