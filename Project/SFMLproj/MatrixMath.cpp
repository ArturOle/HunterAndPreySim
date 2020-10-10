#include "MatrixMath.h"


Matrix::Matrix(int x_in, int y_in)
{
	data_of_matrix.resize(y_in);
	row_of_matrix.resize(x_in);
}


void Matrix::Fill(std::vector<std::vector<float>> data_in)
{

}


void Matrix::Fill(float first_variable, ...)
{
}
