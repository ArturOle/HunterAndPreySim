#include "Storage.h"


Storage::Storage(int f, int h, int c, int d, int b, int o)
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

	obstacles.push_back(new Obstacle(randint(0, width), randint(0, height), randint(0, width), randint(0, height)));
	obstacles.shrink_to_fit();
}


void Storage::ShowDotsData()
{
	ShowVector(foods);
	ShowVector(herbi);
	ShowVector(carni);
}


void Storage::Extract(std::vector<Food*> vec, int j)
{
	int x = foods[j]->dot.getPosition().x;
	int y = foods[j]->dot.getPosition().y;
	delete foods[j];
	foods.erase(foods.begin() + j);
	herbi.push_back(new Herbivore(x, y));
}


void Storage::Extract(std::vector<Herbivore*> vec, int j)
{
	int x = herbi[j]->dot.getPosition().x;
	int y = herbi[j]->dot.getPosition().y;
	delete herbi[j];
	herbi.erase(herbi.begin() + j);
	carni.push_back(new Carnivore(x, y));
}


int Storage::randint(int from, int to)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(from, to);
	int pseudorandom_number = dist(mt);
	return pseudorandom_number;
}


void Storage::Behaviorism_H() 
{
	for (auto& x : herbi)
	{
		x->Decision(this);
	}
}


void Storage::Behaviorism_C()
{
	for (auto& x : carni)
	{
		x->Decision(this);
	}
}


float Storage::CalcDistance(float x_from_in, float y_from_in, float x_to_in, float y_to_in)
{
	float x_move = x_to_in - x_from_in;
	float y_move = y_to_in - y_from_in;

	return sqrtf(pow(x_move, 2) + pow(y_move, 2));
}


void Storage::ClearVectors()
{
	ClearVector(dots);
	ClearVector(bots);
	ClearVector(foods);
	ClearVector(herbi);
	ClearVector(carni);
	ClearVector(obstacles);
}


Storage::~Storage()
{
	ClearVectors();
}
