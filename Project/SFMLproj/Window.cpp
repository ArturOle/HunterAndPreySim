#include "Window.h"


Window::Window()
{
	ReadOnInit("dotdata.txt");
	current_population = { f, h, c };
	for (int i = 0; i < 3; i++)
	{
		std::cout << current_population[i] << std::endl;
	}
	window.setFramerateLimit(60);
}


int Window::ReadOnInit(std::string file_name)
{
	std::string line;
	std::ifstream inFile(file_name);

	if (!inFile.is_open()) return 0;

	while (std::getline(inFile, line))
	{
		char obj = line[0];
		std::string data = "";
		for (int i = 0; i < line.size(); i++)
		{
			if (isdigit(line[i]))
			{
				data = data + line[i];
			}
		}
		std::cout << line << std::endl;
		std::cout << obj << std::endl;
		std::cout << data << std::endl;
		switch (obj) 
		{

		case 'f':
			this->f = stoi(data);

		case 'h':
			this->h = stoi(data);

		case 'c':
			this->c = stoi(data);

		case 'b':
			this->b = stoi(data);
		}
	}
}


void Window::Loop()
{
	GenerateDots(f,b,h,c);
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		Update();
		DrawVector(dots);
		window.display();
		EventHandler();
		Starve();
		Action();
		StopCondition();
		//ShowMeDots();
	}
}


void Window::StopCondition()
{
	if (h > 10 * c) 
		{
		std::cout << "Herbivore won" << std::endl;
		EndSession();
	}
	if (h == 0)
	{
		std::cout << "Carnivore won" << std::endl;
		EndSession();
	}	
}


void Window::EndSession()
{
	window.close();
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
	dots.reserve(f + b + h + c);
	for (int i = 0; i < f; i++)
	{
		AddEntity<Food>(dots);
	}
	for (int i = 0; i < b; i++)
	{
		AddEntity<Bot>(dots);
	}
	for (int i = 0; i < h; i++)
	{
		AddEntity<Herbivore>(dots);
	}
	for (int i = 0; i < c; i++)
	{
		AddEntity<Carnivore>(dots);
	}
}


void Window::Action()
{
	int i, j, max;
	max = dots.size()-1;
	for (i = 0; i < max; i++)
	{
		for (j = i + 1; j < max; j++) 
		{
			if (IsIntersecting(dots[i], dots[j]))
			{
				CarniAction(i, j);
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
			bot->Down();
			bot->Update();
		}
	}
}


void Window::Starve()
{
	int x;
	for ( x = 0; x < dots.size()-1; x++)
	{
		Carnivore* carni = dynamic_cast<Carnivore*>(dots[x]);
		if (carni != nullptr)
		{
			if (carni->CheckTime() >= 0) 
			{
				delete dots[x];
				dots.erase(dots.begin()+x);
				this->c--;
			}
		}
	}
}


void Window::HerbiAction(int i, int j)
{
	Food* type1 = dynamic_cast<Food*>(dots[i]);
	Herbivore* type2 = dynamic_cast<Herbivore*>(dots[j]);

	if (type1 != nullptr && type2 != nullptr)
	{
		//std::cout << "interception of " << dots[i] << " " << dots[j] << std::endl;
		extract<Herbivore>(i);
		AddEntity<Food>(dots);
		h++;
	}
	else
	{
		Food* type1 = dynamic_cast<Food*>(dots[j]);
		Herbivore* type2 = dynamic_cast<Herbivore*>(dots[i]);

		if (type1 != nullptr && type2 != nullptr)
		{
			//std::cout << "interception of " << dots[i] << " " << dots[j] << std::endl;
			extract<Herbivore>(j);
			AddEntity<Food>(dots);
			h++;
		}
	}
}


void Window::CarniAction(int i, int j)
{
	Herbivore* type1 = dynamic_cast<Herbivore*>(dots[i]);
	Carnivore* type2 = dynamic_cast<Carnivore*>(dots[j]);

	if (dynamic_cast<Herbivore*>(dots[i]) != nullptr && dynamic_cast<Carnivore*>(dots[j]) != nullptr)
	{
		CarniHandler(type2, i, j);
		h--;
		c++;
	}
	else
	{
		Herbivore* type1 = dynamic_cast<Herbivore*>(dots[j]);
		Carnivore* type2 = dynamic_cast<Carnivore*>(dots[i]);

		if (type1 != nullptr && type2 != nullptr)
		{
			CarniHandler(type2, j, i);
			h--;
			c++;
		}
		else 
		{
			HerbiAction(i, j);
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
