#include "Window.h"


Window::Window() 
{
	window.setFramerateLimit(60);
}


void Window::Loop()
{
	AddDot();
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		//Dot first(this, 5.0f, 5.0f);
		//IterateDrawing(objects_to_draw);
		//for (int i = 0; i < 5; i++)
		//if (dots.size() < 3) {
			//AddDot();
		//}

		DrawAll();
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

void Window::AddDot()
{
	dots.push_back(new Dot(randint(0, 500), randint(0, 500)));
	dots.shrink_to_fit();
}

void Window::DrawAll()
{
	for (auto x : dots) {
		window.draw(*x);
	}
}

int Window::randint(int from, int to)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 148);
	int pseudorandom_number = dist(mt);
	return pseudorandom_number;
}

/*
void Window::Draw(sf::CircleShape* obj_in)
{	
	window.draw(*obj_in);
}


void Window::AddDrawing(sf::CircleShape* obj_in)
{
	//window.draw(*obj_in);
	objects_to_draw.push_back(obj_in);

}

void Window::IterateDrawing(std::vector<sf::CircleShape*> drawings_to_draw)
{
	for (auto &drawing : drawings_to_draw)
		Draw(drawing);
}

*/
Window::~Window()
{
	for (auto x : dots) {
		delete x;
	}
	dots.clear();
}
