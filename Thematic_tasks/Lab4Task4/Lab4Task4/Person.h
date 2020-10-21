#pragma once
#include <iostream>
#include <string>

class Person
{
	int age = 4;
	int height = 5;
public:
	Person() = default;

	void PersonSay();

	~Person() = default;
};

