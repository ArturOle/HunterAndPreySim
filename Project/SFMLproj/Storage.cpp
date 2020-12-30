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
}


void Storage::ShowDotsData()
{
	ShowVector(foods);
	ShowVector(herbi);
	ShowVector(carni);
}


void Storage::Extract(std::vector<Food*> vec, int j)
{
	int x, y;
	x = foods[j]->dot.getPosition().x;
	y = foods[j]->dot.getPosition().y;
	delete foods[j];
	foods.erase(foods.begin() + j);
	herbi.push_back(new Herbivore(x, y));
}


void Storage::Extract(std::vector<Herbivore*> vec, int j)
{
	int x, y;
	x = herbi[j]->dot.getPosition().x;
	y = herbi[j]->dot.getPosition().y;
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

void Storage::ClearVectors()
{
	ClearVector(dots);
	ClearVector(bots);
	ClearVector(foods);
	ClearVector(herbi);
	ClearVector(carni);
}


Storage::~Storage()
{
	ClearVectors();
}
