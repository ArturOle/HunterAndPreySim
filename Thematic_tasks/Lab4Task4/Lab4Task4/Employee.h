#pragma once
#include "Person.h"

class Employee : public Person
{
	int years_of_work = 100;
	bool retired = false;
public:
	Employee() = default;

	void EmployeeSay();

	~Employee() = default;
};

