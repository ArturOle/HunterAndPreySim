#include "Window.h"


Window::Window() 
{
	window.setFramerateLimit(60);
}


void Window::Loop()
{
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		

		window.display();
		EventHandler();
	}
}


void Window::EventHandler()
{
    sf::Event evnt; // "evnt" name is forced because of "event" is reserved name in C++

    while (window.pollEvent(evnt))
    {
		switch (evnt.type) 
		{

		case(sf::Event::Closed):
			window.close();
			break;
		
		}
    }
}


void Window::Draw(sf::CircleShape *obj_in)
{	
	window.draw(*obj_in);
	objects_to_draw.push_back(*obj_in);
}


Window::~Window()
{
}
