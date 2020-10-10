#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Window
{

public:
	sf::RenderWindow window{ sf::VideoMode{800, 600}, "Hunt it my son" };
	Window();

	void Loop();
	void EventHandler();

	~Window();
};

