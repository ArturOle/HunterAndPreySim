#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <random>
#include <iostream>

#include "Dot.h"
#include "Food.h"
#include "Bot.h"
#include "Carnivore.h"
#include "Herbivore.h"


/*
Requirments achived here:
	- using tamplates ( STL )
	- using polimorphizm ( Bot inherits to Carnivore and Herbivore )
	- streams ( Soon will be saving data there )
	- exceptions ( where are streams there are exceptions )
*/

class Window
{
	sf::RenderWindow window{ sf::VideoMode{800, 600}, "Hunt it my son", sf::Style::Close | sf::Style::Titlebar };  // SFML object creating a window 
	std::vector<Dot*> dots;  // Vector responsible for menaging and storing created dots
	
public:

	Window();  // At initialization we're giving the window apropriet values like maximal fps or antyaliasing

	void Loop();  // Main loop of the game, in this place window is beeing drawn on, cleared
	void EventHandler();  // Takes care of all window events like resizing or closing the window
	void AddDot();  // Adds Dot object to the dots vector
	void AddBot();
	void DrawAll();  // Iterates through dots vector and draws every drawable object from it to the window
	void ShowMeDots();  // Raports names and positions of the Dots in dots vector to the console
	int randint(int from, int to);  // Peudo-random number generator using mt19937 from <random> library

	~Window();  // Destroys all dots inside of the dots vector and cleans the vector
};

