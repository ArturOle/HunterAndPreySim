#pragma once
#include <SFML/Graphics.hpp>


class Obstacle : public sf::Drawable
{
protected:
	sf::RectangleShape rect;
	sf::RenderTarget* target;
	friend class Window;
	friend class Storage;

public:
	int a, b;
	float x_position, y_position;

	Obstacle(int a, int b, float x_position_in, float y_position_in);
	Obstacle() = delete;

	float bound_left();
	float bound_right();
	float bound_top();
	float bound_bottom();

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	~Obstacle() = default;
};

