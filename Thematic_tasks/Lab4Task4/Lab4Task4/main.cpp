#include <crtdbg.h>

#include "Teacher.h"


int main()
{
	Person* person = new Person;
	Employee* employee = new Employee;
	Teacher* teacher = new Teacher;

	person->PersonSay();

	employee->PersonSay();
	employee->EmployeeSay();

	teacher->PersonSay();
	teacher->EmployeeSay();
	teacher->TeacherSay();

	delete (person, employee, teacher);
}