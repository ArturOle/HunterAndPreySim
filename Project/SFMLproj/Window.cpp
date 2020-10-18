#include "Window.h"


Window::Window() 
{
	window.setFramerateLimit(60);
}


void Window::Loop()
{
	GenerateDots();
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);

		DrawAll();
		window.display();
		EventHandler();
		ShowMeDots();
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
	dots.push_back(new Dot(randint(0, 800), randint(0, 600)));
	dots.shrink_to_fit();
}

void Window::AddBot()
{
	bots.push_back(new Bot(randint(0, 800), randint(0, 600)));
	bots.shrink_to_fit();
}


void Window::DrawAll()
{
	DrawVector(dots);
	DrawVector(bots);
}


void Window::ShowMeDots()
{
	std::cout << "Dots in the vector: " << std::endl;
	for (auto x : dots)
	{
		std::cout << x << " at x: " << x->x_position <<" y: "<< x->y_position<< std::endl;
	}
}

void Window::GenerateDots(int f, int b, int h, int c)
{
	for (int i = 0; i < b; i++)
	{
		AddDot();
	}
	for (int i = 0; i < b; i++)
	{
		AddBot();
	}
}


int Window::randint(int from, int to)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(from, to);
	int pseudorandom_number = dist(mt);
	return pseudorandom_number;
}


Window::~Window()
{
	ClearVector(dots);
	ClearVector(bots);
	//ClearVector(herbi);
	//ClearVector(carni);
}
