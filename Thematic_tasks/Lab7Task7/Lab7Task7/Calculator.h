#pragma once
#include <iostream>


template<typename Type>
class Calc
{
	Type num1;
	Type num2;

public:
	Calc(Type num1_in, Type num2_in) 
	{
		num1 = num1_in;
		num2 = num2_in;
	}

	Type Add();
	Type Sub();
	Type Mult();
	Type Divi();

	~Calc() = default;
};


template<typename Type>
inline Type Calc<Type>::Add()
{
	return num1 + num2;
}


template<typename Type>
inline Type Calc<Type>::Sub()
{
	return num1 - num2;
}


template<typename Type>
inline Type Calc<Type>::Mult()
{
	return num1 * num2;
}


template<typename Type>
inline Type Calc<Type>::Divi()
{
	if (num2 == 0)
	{
		std::cout << "ZeroDivisionError" << std::endl;
	}
	else
	{
		return (double)(num1 / num2);
	}
	return 0;
}
