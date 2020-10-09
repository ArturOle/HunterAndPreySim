#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Window
{
	sf::RenderWindow window{ sf::VideoMode{800, 600}, "Hello World" };
public:
	Window();

	void Loop();

};

