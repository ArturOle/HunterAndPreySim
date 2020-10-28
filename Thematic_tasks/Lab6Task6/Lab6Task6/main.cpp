#include <iostream>
#include <crtdbg.h>

#include "Reader.h"

#define _CRTDBG_MAP_ALLOC


int main()
{
	Reader read("tekst.txt");
	std::cout << read.num_of_lines() << std::endl;

	try
	{
		CompNumb<int> cnum1(read.read_cnumber<int>(6));
		cnum1 << std::cout;

		CompNumb<int> cnum2(read.read_cnumber<int>(3));
		cnum2 << std::cout;
		
		CompNumb<int> cnum3(read.read_cnumber<int>(0));
		cnum3 << std::cout;
	}
	catch (std::out_of_range& e) 
	{
		std::cerr << e.what();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}