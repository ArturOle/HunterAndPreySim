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
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

Window::~Window()
{
}
