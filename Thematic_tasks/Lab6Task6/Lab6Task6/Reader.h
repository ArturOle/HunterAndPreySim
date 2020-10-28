#pragma once
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

	template<typename T1>
	std::vector<T1> read_cnumber(int choosen_line);
};


template<typename T1>
inline std::vector<T1> Reader::read_cnumber(int choosen_line)
{
	int i = 0;
	std::vector<T1> pair;
	pair.reserve(2);
	std::string number;
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
					pair.push_back(std::stoi(real_string));
					pair.push_back(std::stoi(imaginary_string));
					return pair;
					pair.clear();
					break;
					
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
