#pragma once
#include "Employee.h"

class Teacher : public Employee
{
public:
	Teacher() = default;

	void TeacherSay();

	~Teacher() = default;
};

