#pragma once
#include <vector>
#include <random>

#include "Carnivore.h"
#include "Herbivore.h"
#include "Food.h"
#include "Obstacle.h"


class Storage
{
private:
	friend class Window;
	friend class Herbivore;
	friend class Carnivore;
	std::vector<Obstacle*> obstacles;
	std::vector<Dot*> dots;  // Vector responsible for menaging and storing created dots
	std::vector<Food*> foods;
	std::vector<Bot*> bots;
	std::vector<Herbivore*> herbi;
	std::vector<Carnivore*> carni;

public:
	Storage() = delete;
	Storage(int f, int h, int c, int d=0, int b=0, int o=0);

	//void GenerateDots(int f, int h, int c, int d = 0, int b = 0, int o = 0);
	void ShowDotsData();
	void Extract(std::vector<Food*> vec, int j);
	void Extract(std::vector<Herbivore*> vec, int j);

	int randint(int from, int to);
	float CalcDistance(float x_from_in, float y_from_in, float x_to_in, float y_to_in);

	void Behaviorism_H();
	void Behaviorism_C();

	template<typename T>
	void AddEntity(std::vector<T*>& vec);   // Adding objects to the dots vector
	template<typename T>
	void ShowVector(std::vector<T*> vec);
	template<typename T>
	void ClearVector(std::vector<T*> vec);

	void ClearVectors();
	~Storage();
};


template<typename T>
inline void Storage::ShowVector(std::vector<T*> vec)
{
	std::cout << "Vector of " << typeid(T).name() << ": " << std::endl;

	for (auto& dot : vec)
	{
		std::cout << dot << "\t" << dot->x_position 
						 << "\t" << dot->y_position << std::endl;
	}
}


template<typename T>
inline void Storage::AddEntity(std::vector<T*>& vec)
{
	vec.push_back(new T(randint(0, width), randint(0, height)));
	vec.shrink_to_fit();
}


template<typename T>
inline void Storage::ClearVector(std::vector<T*> vec)
{
	for (auto x : vec)
	{
		delete x;
	}
	vec.clear();
}