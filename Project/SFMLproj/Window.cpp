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
		}
	}
	return 1;
}


void Window::Loop()
{
	GenerateDots(0, 0, f, h, c);

	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		Update();
		DrawVectors();
		window.display();
		EventHandler();
		Starve();
		Action();
		Behaviorism_C();
		Behaviorism_H();
		//WriteData("sessiondata.txt");
		ShowDotsData();
		StopCondition();
	}
}


void Window::DrawVectors() 
{
	DrawVector(dots);
	DrawVector(bots);
	DrawVector(foods);
	DrawVector(herbi);
	DrawVector(carni);
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


void Window::ShowDotsData()
{
	ShowVector(foods);
	ShowVector(herbi);
	ShowVector(carni);
}


void Window::GenerateDots(int d, int b, int f, int h, int c)
{
	for (int i = 0; i < d; i++)
	{
		AddEntity<Dot>(dots);
	}
	for (int i = 0; i < b; i++)
	{
		AddEntity<Bot>(bots);
	}
	for (int i = 0; i < f; i++)
	{
		AddEntity<Food>(foods);
	}
	for (int i = 0; i < h; i++)
	{
		AddEntity<Herbivore>(herbi);
	}
	for (int i = 0; i < c; i++)
	{
		AddEntity<Carnivore>(carni);
	}
}


void Window::Action()
{
	HerbiAction();
	CarniAction();
}


void Window::Update()
{
	for (Bot* x : bots)
	{
		x->Update();	
	}

	for (Herbivore* x : herbi)
	{
		x->Update();
	}

	for (Carnivore* x : carni)
	{
		x->Update();
	}
}


void Window::Starve()
{
	int x;

	for ( x = 0; x < carni.size(); x++)
	{
		if (carni[x]->CheckTime() >= 0) 
		{
			delete carni[x];
			carni.erase(carni.begin()+x);
			this->c--;
		}
	}
}


float Window::CalcDistance(float x_from_in, float y_from_in, float x_to_in, float y_to_in)
{
	float x_move = x_to_in - x_from_in;
	float y_move = y_to_in - y_from_in;

	return sqrtf(pow(x_move, 2) + pow(y_move, 2));
}


void Window::HerbiAction()
{
	int i, j;
	
	for (i = 0; i < herbi.size(); i++)
	{
		for (j = 0; j < foods.size(); j++)
		{
			if(IsIntersecting(herbi[i], foods[j]))
			{
				Extract(foods, j);
				AddEntity<Food>(foods);
				h++;
			}
		}
	}
}


void Window::CarniAction()
{
	int i, j;

	for (i = 0; i < carni.size(); i++)
	{
		for (j = 0; j < herbi.size(); j++)
		{
			if (IsIntersecting(carni[i], herbi[j]))
			{
				CarniHandler(carni[i], j);
				h--;
				c++;
			}
		}
	}
}


void Window::Behaviorism_H()
{
	bool run = false;
	float shortest_distance, distance;

	for (auto& x: herbi)
	{
		shortest_distance = INFINITY;

		for (auto& y : foods)
		{
			if (run == false)
			{
				distance = CalcDistance(x->x_position, x->y_position, y->x_position, y->y_position);

				if (shortest_distance > distance)
				{
					shortest_distance = distance;
					x->SeakFood(y->x_position, y->y_position);
				}
			}
		}

		for (auto& y : carni) 
		{
			distance = CalcDistance(x->x_position, x->y_position, y->x_position, y->y_position);

			if (100 > distance)
			{
				x->Flee(y->x_position, y->y_position);
				run = true;
			}
			else
			{
				run = false;
			}
		}
	}
}


void Window::Extract(std::vector<Food*> vec, int j)
{
	int x, y;
	x = foods[j]->dot.getPosition().x;
	y = foods[j]->dot.getPosition().y;
	delete foods[j];
	foods.erase(foods.begin()+j);
	herbi.push_back(new Herbivore(x, y));
}


void Window::Extract(std::vector<Herbivore*> vec, int j)
{
	int x, y;
	x = herbi[j]->dot.getPosition().x;
	y = herbi[j]->dot.getPosition().y;
	delete herbi[j];
	herbi.erase(herbi.begin() + j);
	carni.push_back(new Carnivore(x, y));
}


void Window::Behaviorism_C()
{
	float shortest_distance, distance;

	for (auto &x: carni)
	{
		shortest_distance = INFINITY;

		for (auto& y: herbi)
		{
			distance = CalcDistance(x->dot.getPosition().x, x->dot.getPosition().y, y->dot.getPosition().x, y->dot.getPosition().y);

			if (distance < shortest_distance)
			{
				shortest_distance = distance;
				x->Hunt(y);
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


void Window::ClearVectors()
{
	ClearVector(dots);
	ClearVector(bots);
	ClearVector(foods);
	ClearVector(herbi);
	ClearVector(carni);
}


Window::~Window()
{
	ClearVectors();
}
