#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <sstream>
#include <any>

#include "MyExceptions.h"
#include "Obstacle.h"
#include "Food.h"
#include "Carnivore.h"
#include "Herbivore.h"


/*
Requirments achived here:
	- using tamplates ( STL and SFML, and self-made)
	- using polimorphizm ( Carnivore and Herbivore inherits from Bot, Bot inherits from Dot, Dot inherits from sf::drawable )
	- streams ( saving data and reading data )
	- exceptions
*/


#define width 1000  //screen width
#define height 800  // screen height


class Window
{
	int f, h, c;
	std::vector<int> current_population = {0, 0, 0};  // Keeps track on quantity of particular types of dots {food, herbivore, carnivore)
	sf::RenderWindow window{ sf::VideoMode{width, height}, "Hunt it my son", sf::Style::Close | sf::Style::Titlebar };  // SFML object creating a window 
	
	std::vector<Obstacle*> obstacles;
	std::vector<Dot*> dots;  // Vector responsible for menaging and storing created dots
	std::vector<Food*> foods;
	std::vector<Bot*> bots;
	std::vector<Herbivore*> herbi;
	std::vector<Carnivore*> carni;

public:

	Window();  // At initialization we're giving the window apropriet values like maximal fps or antyaliasing

	int ReadOnInit(std::string file_name);  //Reads txt file for information about quantity of dots of particular type

	void Loop();  // Main loop of the game, in this place window is beeing drawn on, cleared
	void StopCondition();  // Check for winning condidtion of herbivore and carnivore
	void EndSession(std::string res, std::string file_name);  // Stops the session, writes result to the session data
	void EventHandler();  // Takes care of all window events like resizing or closing the window
	void WriteData(std::string file_name);  // Writes current population of food, herbivores and carnivors to sessiondata.txt in every frame
	void ShowDotsData();

	void GenerateDots(int d=1, int b=1, int f=5, int h=1, int c=1);  // Resizes dots vector and fill it with quantities read by ReadOnInit /line 39/ 
	void Action();  // Checks types of intersecting objects end executes procedures ( for example wen carnivor hits herbivore, herbivore is eaten, carnvore multiplies)
	void Update();  // Updates state of every dot in the game 
	void Starve();  // Method responsible for checking on carnivores lifetime and if its too long it dies
	void DrawVectors();

	 // Expansion for Action method for herbivores 
	void HerbiAction();
	void CarniAction();  // Expansion for Action method for carnivores
	void Behaviorism_H();  // Behaviors and choices of action of herbivores
	void Behaviorism_C();  // Behaviors of carnivores 
	void Extract(std::vector<Food*> vec, int j);
	void Extract(std::vector<Herbivore*> vec, int j);


	template<typename T>
	void ShowVector(std::vector<T*> vec);
	template<typename T>
	int AddEntity(std::vector<T*> &vec);   // Adding objects to the dots vector
	template<typename T1, typename T2>
	bool IsIntersecting(T1 obj_1, T2 obj_2);  // Responsible for detecting intersections among the objects from dots vector
	template<typename T>
	void ClearVector(std::vector<T> v_name);  // Deletes all objects and clears vector 
	template<typename V>
	void DrawVector(V v_names);
	template<typename T2>
	void CarniHandler(T2 type2, int j);  // Helps carnivore eat and multiply 

	int randint(int from, int to);  // Peudo-random number generator using mt19937 from <random> library
	void ClearVectors();
	float CalcDistance(float x_from_in, float y_from_in, float x_to_in, float y_to_in);  //

	~Window();  // Destroys all dots inside of the dots vector and cleans the vector
};


template<typename T>
inline void Window::ShowVector(std::vector<T*> vec)
{
	std::cout << "Vector of " << typeid(T).name() << ": " << std::endl;

	for (auto& dot : vec)
	{
		std::cout << dot << std::endl;
	}
}


template<typename T>
inline int Window::AddEntity(std::vector<T*> &vec)
{
	vec.push_back(new T(randint(0, width), randint(0, height)));
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


template<typename V>
inline void Window::DrawVector(V v_names)
{
	for (auto& x : v_names)
	{
		window.draw(*x);
	}
}


template< typename T2>
inline void Window::CarniHandler(T2 type2, int j)
{
	type2->CheckTime();
	Extract(herbi, j);
	type2->AddTime();
}