#pragma once
#include <SFML/Graphics.hpp>


class Obstacle : public sf::Drawable
{
protected:
	sf::RectangleShape rect;
	sf::RenderTarget* target;
	friend class Window;

public:
	int width, height;
	float x_position, y_position;

	Obstacle(int width, int height, float x_position, float y_position);
	Obstacle() = delete;

	void bound_left();
	void bound_right();
	void bound_top();
	void bound_bottom();

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	~Obstacle() = default;
};

