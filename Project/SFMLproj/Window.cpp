#include "Window.h"

Window::Window() 
{
	
	window.setFramerateLimit(60);
}

void Window::Loop()
{
	while (true)
	{
		window.clear(sf::Color::Black);
		window.display();
	}
}