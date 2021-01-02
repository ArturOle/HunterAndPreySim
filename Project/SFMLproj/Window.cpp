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




void Window::Loop()
{
	storage = new Storage(f, h, c);

	while (window.isOpen())
	{
		window.clear(sf::Color::Black);
		Update();
		DrawVectors();
		window.display();
		EventHandler();
		Starve();
		Action();
		storage->Behaviorism_C();
		storage->Behaviorism_H();
		//WriteData("sessiondata.txt");
		//ShowDotsData();
		StopCondition();
	}
}


void Window::DrawVectors() 
{
	DrawVector(storage->dots);
	DrawVector(storage->bots);
	DrawVector(storage->foods);
	DrawVector(storage->herbi);
	DrawVector(storage->carni);
}


void Window::Action()
{
	HerbiAction();
	CarniAction();
}


void Window::ShowDotsData()
{
	storage->ShowDotsData();
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



void Window::Update()
{
	for (Bot* x : storage->bots)
	{
		x->Update();	
	}

	for (Herbivore* x : storage->herbi)
	{
		x->Update();
	}

	for (Carnivore* x : storage->carni)
	{
		x->Update();
	}
}


void Window::Starve()
{
	for (int x = 0; x < storage->carni.size(); x++)
	{
		if (storage->carni[x]->CheckTime() >= 0) 
		{
			delete storage->carni[x];
			storage->carni.erase(storage->carni.begin()+x);
			this->c--;
		}
	}
}


void Window::HerbiAction()
{
	int i, j;
	
	for (i = 0; i < storage->herbi.size(); i++)
	{
		for (j = 0; j < storage->foods.size(); j++)
		{
			if(IsIntersecting(storage->herbi[i], storage->foods[j]))
			{
				storage->Extract(storage->foods, j);
				storage->AddEntity<Food>(storage->foods);
				h++;
			}
		}
	}
}


void Window::CarniAction()
{
	int i, j;

	for (i = 0; i < storage->carni.size(); i++)
	{
		for (j = 0; j < storage->herbi.size(); j++)
		{
			if (IsIntersecting(storage->carni[i], storage->herbi[j]))
			{
				CarniHandler(storage->carni[i], j);
				h--;
				c++;
			}
		}
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


Window::~Window()
{
	delete storage;
}
