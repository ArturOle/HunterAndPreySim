#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <exception>
#include <iostream>
#include <array>


class ZeroDivision : public std::exception
{
public:
	ZeroDivision() {};
	const char* what() const throw () {
		return "Zero Dyvision Error";
	}
};


class OutOfRange : public std::exception
{
public:
	OutOfRange() {};
	const char* what() const throw () {
		return "Out of range Error";
	}
};


class CannotOpen : public std::exception
{
public:
	CannotOpen() {};
	const char* what() const throw () {
		return "No such file";
	}
};


class GoodClass
{
	std::array<int, 5> my_storage = { -2, -1, 0, 1, 2 };
	int i;
public:

	int SecureFunction1()
	{
		try {
			for (i = 0; i < my_storage.size()-1; i++)
			{
				if (my_storage[i + 1] == 0)
					throw ZeroDivision();
				float result = my_storage[i] / my_storage[i + 1];
				std::cout << result << std::endl;
			}
			return 0; //if all goes well
		}
		catch (const ZeroDivision& e) {
			std::cerr << e.what() << std::endl;
			return -1;
		}
	}

	int SecureFunction2()
	{
		try 
		{
			for (i = 0; i <= my_storage.size(); i++)
			{
				if (i == my_storage.size())
					throw OutOfRange();
				std::cout << my_storage[i] << std::endl;
			}
			return 0;
		}

		catch (const OutOfRange& e) {
			std::cerr << e.what() << std::endl;
			return -1;
		}
	}

	int SecureFunction3()
	{
		try
		{
			FILE* fp;
			fopen_s(&fp, "txt.txt", "r");
			if (fp == NULL) 
			{
				throw CannotOpen();
			}

			char* line = NULL;
			size_t len = 0;
			fgets(line, len, fp);
			printf("%s", line);
			fclose(fp);
			if (line)
				free(line);
			return 0;
		}
		catch (const CannotOpen& e) 
		{
			std::cerr << e.what() << std::endl;
		}
	}
};


int main()
{
	GoodClass someclass;
	someclass.SecureFunction1();
	someclass.SecureFunction2();
	someclass.SecureFunction3();
	std::cout << "Congrats, you made it!" << std::endl;
}