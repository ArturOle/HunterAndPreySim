#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <random>

#include "Dot.h"


class Window
{
	sf::RenderWindow window{ sf::VideoMode{800, 600}, "Hunt it my son", sf::Style::Close | sf::Style::Titlebar };
	std::vector<Dot*> dots;
	//Dot* dot = new Dot(20, 20);
public:

	Window();

	void Loop();
	void EventHandler();
	void AddDot();
	void DrawAll();
	int randint(int from, int to);
	~Window();
};

