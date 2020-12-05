#include "Window.h"


Window::Window()
{
	try 
	{
		ReadOnInit("dotdata.txt");
		current_population = { f, h, c };
	}
	catch (FileNotOpened& e)
	{
		e.what();
	}

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

	if (!inFile.is_open()) throw FileNotOpened();

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

		switch (obj) 
		{
		case 'f':
			this->f = stoi(data);
			break;

		case 'c':
			this->c = stoi(data);
			break;

		case 'h':
			this->h = stoi(data);
			break;

		case 'b':
			this->b = stoi(data);
			break;
		}
	}
	return 1;
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
		Behaviorism_C();
		Behaviorism_H();
		//WriteData("sessiondata.txt");
		StopCondition();
		//ShowMeDots();
	}
}


void Window::StopCondition()
{
	if (h > 20 * c) 
	{
		std::string result = "Herbivore won";
		EndSession(result, "sessiondata.txt");
	}
	if (h == 0)
	{
		std::string result = "Carnivore won";
		EndSession(result, "sessiondata.txt");
	}	
}


void Window::EndSession(std::string res, std::string file_name )
{
	std::ofstream FILE(file_name, std::ios::app);

	if (FILE.is_open())
	{
		FILE << "result;" + res + ";\n";
		FILE.close();
	}

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


void Window::WriteData(std::string file_name)
{
	std::string line = std::to_string(f)+";"+std::to_string(h)+";"+ std::to_string(c)+";\n";
	std::ofstream FILE(file_name, std::ios::app);

	if (FILE.is_open())
	{
		FILE << line;
		FILE.close();
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
	max = dots.size();

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

	for ( x = 0; x < dots.size(); x++)
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


float Window::CalcDistance(float x_from_in, float y_from_in, float x_to_in, float y_to_in)
{
	float x_move = x_to_in - x_from_in;
	float y_move = y_to_in - y_from_in;

	return sqrtf(pow(x_move, 2) + pow(y_move, 2));
}


void Window::HerbiAction(int i, int j)
{
	Food* type1 = dynamic_cast<Food*>(dots[i]);
	Herbivore* type2 = dynamic_cast<Herbivore*>(dots[j]);

	if (type1 != nullptr && type2 != nullptr)
	{
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
		Herbivore* type1 = dynamic_cast<Herbivore*>(this->dots[j]);
		Carnivore* type2 = dynamic_cast<Carnivore*>(this->dots[i]);

		if (type1 != nullptr && type2 != nullptr)
		{
			CarniHandler(type2, j, i);
			this->h--;
			this->c++;
		}
		else 
		{
			HerbiAction(i, j);
		}
	}
}


void Window::Behaviorism_H()
{
	bool run = false;
	float shortest_distance, distance;

	for (auto &x: dots)
	{
		Herbivore* type1 = dynamic_cast<Herbivore*>(x);
		shortest_distance = INFINITY;

		if (type1 != nullptr)
		{
			for (auto& y : dots)
			{
				if(run == false)
				{
					Food* type2 = dynamic_cast<Food*>(y);

					if (type2 != nullptr)
					{
						distance = CalcDistance(x->x_position, x->y_position, y->x_position, y->y_position);

						if (shortest_distance > distance)
						{
							shortest_distance = distance;
							type1->SeakFood(y->x_position, y->y_position);
						}
					}
				}
				Carnivore* type2 = dynamic_cast<Carnivore*>(y);

				if (type2 != nullptr)
				{
					distance = CalcDistance(x->x_position, x->y_position, y->x_position, y->y_position);

					if (100 > distance)
					{
						type1->Flee(y->x_position, y->y_position);
						run = true;
					}
					else
					{
						run = false;
					}
				}
			}
		}
	}
}


void Window::Behaviorism_C()
{
	float shortest_distance, distance;

	for (auto& x: dots)
	{
		Carnivore* type1 = dynamic_cast<Carnivore*>(x);
		shortest_distance = INFINITY;

		if (type1 != nullptr)
		{
			for (auto& y: dots)
			{
				Herbivore* type2 = dynamic_cast<Herbivore*>(y);

				if (type2 != nullptr)
				{
					distance = CalcDistance(x->dot.getPosition().x, x->dot.getPosition().y, y->dot.getPosition().x, y->dot.getPosition().y);

					if (distance < shortest_distance)
					{
						shortest_distance = distance;
						type1->Hunt(type2);
					}
				}
			}
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
