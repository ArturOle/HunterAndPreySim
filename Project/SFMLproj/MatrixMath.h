#pragma once

#include <vector>

/*
Tool class for neural network implementation.

Criteria acquired here:
	- use of templates( from STL lib )

*/

class Matrix
{
	// Sizes of the matrix
	std::vector<std::vector<float>> data_of_matrix;
	std::vector<float> row_of_matrix;

public:

	// Constructors
	Matrix();
	Matrix(int x_in, int y_in); // Takes x and y value as dimentions and creates vector with those parameters

	// Methods
	void Fill(std::vector<std::vector<float>> data_in);
	void Fill(float first_variable, ...);
};
