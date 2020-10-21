#pragma once
#include "Person.h"

class Employee : public Person
{
public:
	Employee() = default;

	void EmployeeSay();

	~Employee() = default;
};

