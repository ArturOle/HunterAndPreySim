#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <any>

#include "MyExceptions.h"
#include "Storage.h"


/*
Requirments achived here:
	- using tamplates ( STL and SFML, and self-made)
	- using polimorphizm ( Carnivore and Herbivore inherits from Bot, Bot inherits from Dot, Dot inherits from sf::drawable )
	- streams ( saving data and reading data )
	- exceptions
*/


class Window
{
	int f, h, c;
	std::vector<int> current_population = {0, 0, 0};  // Keeps track on quantity of particular types of dots {food, herbivore, carnivore)
	sf::RenderWindow window{ sf::VideoMode{width, height}, "Hunt it my son", sf::Style::Close | sf::Style::Titlebar };  // SFML object creating a window 
	
	Storage* storage; 

public:

	Window();  // At initialization we're giving the window apropriet values like maximal fps or antyaliasing

	int ReadOnInit(std::string file_name);  //Reads txt file for information about quantity of dots of particular type

	void Loop();  // Main loop of the game, in this place window is beeing drawn on, cleared
	void StopCondition();  // Check for winning condidtion of herbivore and carnivore
	void EndSession(std::string res, std::string file_name);  // Stops the session, writes result to the session data
	void EventHandler();  // Takes care of all window events like resizing or closing the window
	void WriteData(std::string file_name);  // Writes current population of food, herbivores and carnivors to sessiondata.txt in every frame
	void ShowDotsData();

	void Action();  // Checks types of intersecting objects end executes procedures ( for example wen carnivor hits herbivore, herbivore is eaten, carnvore multiplies)
	void Update();  // Updates state of every dot in the game 
	void Starve();  // Method responsible for checking on carnivores lifetime and if its too long it dies
	void DrawVectors();

	 // Expansion for Action method for herbivores 
	void HerbiAction();
	void CarniAction();  // Expansion for Action method for carnivores
	void Behaviorism_H();  // Behaviors and choices of action of herbivores
	void Behaviorism_C();  // Behaviors of carnivores 

	template<typename T1, typename T2>
	bool IsIntersecting(T1 obj_1, T2 obj_2);  // Responsible for detecting intersections among the objects from dots vector
	template<typename V>
	void DrawVector(V v_names);
	template<typename T2>
	void CarniHandler(T2 type2, int j);  // Helps carnivore eat and multiply 

	float CalcDistance(float x_from_in, float y_from_in, float x_to_in, float y_to_in);  //

	~Window();  // Destroys all dots inside of the dots vector and cleans the vector
};


template<typename T1, typename T2>
inline bool Window::IsIntersecting(T1 obj_1, T2 obj_2)
{
	return obj_1->dot.getGlobalBounds().intersects(obj_2->dot.getGlobalBounds());
}


template<typename V>
inline void Window::DrawVector(V v_names)
{
	for (auto& x : v_names)
	{
		window.draw(x->dot);
	}
}


template< typename T2>
inline void Window::CarniHandler(T2 type2, int j)
{
	type2->CheckTime();
	storage->Extract(storage->herbi, j);
	type2->AddTime();
}