#include "Calculator.h"
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

int main()
{
	Calc<int> calc1(20, 10);
	std::cout << calc1.Add() << std::endl;
	std::cout << calc1.Sub() << std::endl;
	std::cout << calc1.Mult() << std::endl;
	std::cout << calc1.Divi() << std::endl;
	
	Calc<int> calc2(13, 0);
	std::cout << calc2.Add() << std::endl;
	std::cout << calc2.Sub() << std::endl;
	std::cout << calc2.Mult() << std::endl;
	std::cout << calc2.Divi() << std::endl;

	Calc<int> calc3(-1333, 33);
	std::cout << calc3.Add() << std::endl;
	std::cout << calc3.Sub() << std::endl;
	std::cout << calc3.Mult() << std::endl;
	std::cout << calc3.Divi() << std::endl;

	Calc<float> calc4(14.4344, 0.0004);
	std::cout << calc4.Add() << std::endl;
	std::cout << calc4.Sub() << std::endl;
	std::cout << calc4.Mult() << std::endl;
	std::cout << calc4.Divi() << std::endl;

	Calc<double> calc5(20.23424234234, 1343.444);
	std::cout << calc5.Add() << std::endl;
	std::cout << calc5.Sub() << std::endl;
	std::cout << calc5.Mult() << std::endl;
	std::cout << calc5.Divi() << std::endl;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}