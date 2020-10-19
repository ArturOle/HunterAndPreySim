#include "ZOO.h"

ZOO::ZOO(int new_quantity)
{
	quantity = new_quantity;
	for(int x = 0; x < quantity; x++)
	{
		int i = randint(0, 3);
		if(i % 3 == 0) 
		{
			censos.push_back(new Axolotl(randint(1, 3)));
		}
		else if (i % 3 ==1)
		{
			censos.push_back(new Glonk(randint(1, 3)));
		}
		else
		{
			censos.push_back(new RedPanda(randint(1, 3)));
		}
	}
	censos.shrink_to_fit();
}


int ZOO::randint(int from, int to)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(from, to);
	int pseudorandom_number = dist(mt);
	return pseudorandom_number;
}

ZOO::~ZOO()
{
	//for (auto& x : censos)
	//{
		//delete x;
	//}
	censos.clear();
}
