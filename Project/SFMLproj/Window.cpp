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
		Update();
		DrawVector(dots);
		window.display();
		EventHandler();
		Action();
		//ShowMeDots();
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
	dots.push_back(new Bot(randint(0, 800), randint(0, 600)));
	dots.shrink_to_fit();
}


void Window::AddHerbi()
{
	dots.push_back(new Herbivore(randint(0, 800), randint(0, 600)));
	dots.shrink_to_fit();
}


void Window::AddCarni()
{
	dots.push_back(new Carnivore(randint(0, 800), randint(0, 600)));
	dots.shrink_to_fit();
}


void Window::AddFood()
{
	dots.push_back(new Food(randint(0, 800), randint(0, 600)));
	dots.shrink_to_fit();
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
	for (int i = 0; i < f; i++)
	{
		AddFood();
	}
	for (int i = 0; i < b; i++)
	{
		AddBot();
	}
	for (int i = 0; i < h; i++)
	{
		AddHerbi();
	}
	for (int i = 0; i < c; i++)
	{
		AddCarni();
	}
}


void Window::Action()
{
	int x, y;
	for (int i = 0; i < dots.size()-1; i++)
	{
		for (int j = i + 1; j < dots.size()-1; j++) 
		{
			if (IsIntersecting(dots[i], dots[j]))
			{
				Herbivore* type1 = dynamic_cast<Herbivore*>(dots[i]);
				Carnivore* type2 = dynamic_cast<Carnivore*>(dots[j]);
				
				if (type1 != nullptr && type2 != nullptr)
				{
					std::cout << "interception of " << dots[i] << " " << dots[j] << std::endl;
					x = dots[i]->dot.getPosition().x;
					y = dots[i]->dot.getPosition().y;
					delete dots[i];
					dots[i] = new Carnivore(x, y);
				}
				else
				{
					Food*	   type1 = dynamic_cast<Food*     >(dots[i]);
					Herbivore* type2 = dynamic_cast<Herbivore*>(dots[j]);

					if (type1 != nullptr && type2 != nullptr)
					{
						std::cout << "interception of " << dots[i] << " " << dots[j] << std::endl;
						x = dots[i]->dot.getPosition().x;
						y = dots[i]->dot.getPosition().y;
						delete dots[i];
						dots[i] = new Herbivore(x, y);
						AddFood();
					}
				}
			}
		}
	}
}


void Window::Update()
{
	for (Dot* x : dots)
	{
		Bot* bot = dynamic_cast<Bot*>(x);
		if (bot != NULL)
		{
			bot->Update();
		}
	}
}


void Window::Test()
{
	for(Dot* &x : dots)
	{
		Bot* bot = dynamic_cast<Bot*>(x);
		if(bot != NULL)
		{
			bot->GoDown();
			bot->Update();
		}
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
}
