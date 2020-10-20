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

#define width 800
#define height 600

class Window
{
	sf::RenderWindow window{ sf::VideoMode{width, height}, "Hunt it my son", sf::Style::Close | sf::Style::Titlebar };  // SFML object creating a window 
	std::vector<Dot*> dots;  // Vector responsible for menaging and storing created dots
	//std::vector<Bot*> bots;

	//std::vector<Herbivore*> herbi;
	//std::vector<Carnivore*> carni;
	
public:

	Window();  // At initialization we're giving the window apropriet values like maximal fps or antyaliasing

	void Loop();  // Main loop of the game, in this place window is beeing drawn on, cleared
	void EventHandler();  // Takes care of all window events like resizing or closing the window

	void AddDot();  // Adding objects to the dots vector
	void AddBot();
	void AddHerbi();
	void AddCarni();
	void AddFood();

	void DrawAll();  // Iterates through dots vector and draws every drawable object from it to the window
	void ShowMeDots();  // Raports names and positions of the Dots in dots vector to the console
	void GenerateDots(int f=2, int b=3, int h=4, int c=5);
	void Update();
	void Test();

	template<typename T>
	void ClearVector(std::vector<T> v_name);
	template<typename T>
	void DrawVector(std::vector<T> v_name);

	int randint(int from, int to);  // Peudo-random number generator using mt19937 from <random> library

	~Window();  // Destroys all dots inside of the dots vector and cleans the vector
};

template<typename T>
inline void Window::ClearVector(std::vector<T> v_name)
{
	for (auto x : v_name) 
	{
		delete x;
	}
	v_name.clear();

}

template<typename T>
inline void Window::DrawVector(std::vector<T> v_name)
{
	for (auto x: v_name)
	{
		window.draw(*x);
	}
}
