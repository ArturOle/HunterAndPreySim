#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <exception>

#include "CompNumb.h"


class Reader
{
	std::string filename;
	std::string line;
	std::ofstream file_pointer;
	int quantity_lines;

public:
	Reader(std::string filename_in);

	int num_of_lines();

	template<typename R, typename I>
	CompNumb<R, I> read_cnumber(int choosen_line);
};


template<typename R, typename I>
inline CompNumb<R, I> Reader::read_cnumber(int choosen_line)
{
	CompNumb<int, int>* complex_num;
	std::string number;
	int i = 0;
	std::ifstream inFile(filename);
	if (inFile.is_open())
	{
		if(this->quantity_lines >= choosen_line && choosen_line > 0 )
		{ 
			while (std::getline(inFile, number))
			{
				if (i == choosen_line - 1)
				{
					std::stringstream ss(number);
					std::string real_string;
					std::string imaginary_string;
					std::getline(ss, real_string, '#');
					std::getline(ss, imaginary_string, '#');
					complex_num = new CompNumb<int, int>(std::stoi(real_string), std::stoi(imaginary_string));
					return *complex_num;
					break;
					delete complex_num;
				}
				i += 1;
			}
		}
		else
		{
			throw std::out_of_range("No such line");
		}
	}
	else
	{
		throw std::exception("No such file");
	}
}

