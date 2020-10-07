#pragma once
#include <vector>

/*
Tool class for neural network implementation.

Criteria acquired here:
	- use of templates( from STL lib )

*/

template<typename T>
class Matrix
{
	// Sizes of the matrix
	int x; 
	int y;

public:
	// Constructors
	Matrix(int x_in, int y_in); // Takes x and y value as dimentions and creates vector with those parameters
	Matrix(std::vector<T> v);

};

