#pragma once
#include "Shape.h"

class Triangle : virtual public Shape
{
public:
	Triangle(int a=0, int b=0) : Shape(a, b) {}

	int GetArea();
};
