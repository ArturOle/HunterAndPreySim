#include <iostream>

#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"


int main()
{
	Shape *shape;
	Triangle triangle(6, 6);
	Rectangle rectangle(10, 10);

	shape = &triangle;
	std::cout << shape->GetArea() << std::endl;

	shape = &rectangle;
	std::cout << shape->GetArea() << std::endl;

	return 0;
}