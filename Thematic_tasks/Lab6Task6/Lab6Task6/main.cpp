#include <iostream>

#include "Reader.h"


int main()
{
	Reader read("tekst.txt");
	std::cout << read.num_of_lines() << std::endl;

	try
	{
		CompNumb<int, int> cnum = read.read_cnumber<int, int>(6);
		cnum << std::cout;

		cnum = read.read_cnumber<int, int>(3);
		cnum << std::cout;

		cnum = read.read_cnumber<int, int>(0);
		cnum << std::cout;
	}
	catch (std::out_of_range& e) 
	{
		std::cerr << e.what();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}