#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

#include "Dot.h"


class Window
{
	sf::RenderWindow window{ sf::VideoMode{800, 600}, "Hunt it my son", sf::Style::Close | sf::Style::Titlebar };
	std::vector<sf::CircleShape> objects_to_draw;
	//Dot* first = new Dot;
public:

	Window();

	void Loop();
	void EventHandler();
	void Draw(sf::CircleShape *obj_in);

	~Window();
};

