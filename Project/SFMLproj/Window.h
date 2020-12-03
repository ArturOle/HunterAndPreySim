#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
//#include <random>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Food.h"
#include "Carnivore.h"
#include "Herbivore.h"


/*
Requirments achived here:
	- using tamplates ( STL )
	- using polimorphizm ( Bot inherits to Carnivore and Herbivore )
	- streams ( saving data and reading data )
	- exceptions ( where are streams there are exceptions )
*/

#define width 800
#define height 600

class Window
{
	int f, b, h, c;
	std::vector<int> current_population = {0, 0, 0};  // Keeps track on quantity of particular types of dots {food, herbivore, carnivore)
	sf::RenderWindow window{ sf::VideoMode{width, height}, "Hunt it my son", sf::Style::Close | sf::Style::Titlebar };  // SFML object creating a window 
	std::vector<Dot*> dots;  // Vector responsible for menaging and storing created dots
	
public:

	Window();  // At initialization we're giving the window apropriet values like maximal fps or antyaliasing

	int ReadOnInit(std::string file_name);  //Reads txt file for information about quantity of dots of particular type

	void Loop();  // Main loop of the game, in this place window is beeing drawn on, cleared
	void StopCondition();  // Check for winning condidtion of herbivore and carnivore
	void EndSession(std::string res, std::string file_name);  // Stops the session, writes result to the session data
	void EventHandler();  // Takes care of all window events like resizing or closing the window
	void WriteData(std::string file_name);  // Writes current population of food, herbivores and carnivors to sessiondata.txt in every frame

	void ShowMeDots();  // Raports names and positions of the Dots in dots vector to the console
	void GenerateDots(int f=10, int b=0, int h=1, int c=1);  // Resizes dots vector and fill it with quantities read by ReadOnInit /line 39/ 
	void Action();  // Checks types of intersecting objects end executes procedures ( for example wen carnivor hits herbivore, herbivore is eaten, carnvore multiplies)
	void Update();  // Updates state of every dot in the game 
	void Test();  // Movement test
	void Starve();  // Method responsible for checking on carnivores lifetime and if its too long it dies

	void HerbiAction(int i, int j);  // Expansion for Action method for herbivores 
	void CarniAction(int i, int j);  // Expansion for Action method for carnivores

	template<typename T>
	int AddEntity(std::vector<Dot*> &vec);   // Adding objects to the dots vector
	template<typename T1, typename T2>
	bool IsIntersecting(T1 obj_1, T2 obj_2);  // Responsible for detecting intersections among the objects from dots vector
	template<typename T>
	void ClearVector(std::vector<T> v_name);  // Deletes all objects and clears vector 
	template<typename T>
	void DrawVector(std::vector<T> v_name);  // Iterates through dots vector and draws every drawable object from it to the window
	template<typename T>
	void extract(int i);  // Method responsible for eating and multipling of dots
	template<typename T2>
	void CarniHandler(T2 type2, int i, int j);  // Helps carnivore eat and multiply 

	int randint(int from, int to);  // Peudo-random number generator using mt19937 from <random> library
	
	~Window();  // Destroys all dots inside of the dots vector and cleans the vector
};


template<typename T>
inline int Window::AddEntity(std::vector<Dot*> &vec)
{
	vec.push_back(new T(randint(0, 800), randint(0, 600)));
	vec.shrink_to_fit();
	return 0;
}


template<typename T1, typename T2>
inline bool Window::IsIntersecting(T1 obj_1, T2 obj_2)
{
	return obj_1->dot.getGlobalBounds().intersects(obj_2->dot.getGlobalBounds());
}


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


template<typename T>
inline void Window::extract(int i)
{
	int x, y;
	x = dots[i]->dot.getPosition().x;
	y = dots[i]->dot.getPosition().y;
	delete dots[i];
	dots[i] = new T(x, y);
}


template< typename T2>
inline void Window::CarniHandler(T2 type2, int i, int j)
{
	type2->CheckTime();
	extract<Carnivore>(i);
	type2->AddTime();
}