#include <exception>
#include <iostream>
#include <string>
#include <array>
#include <fstream>

class GoodClass
{
	int i;
	std::array<int, 5> my_storage = { -2, -1, 0, 1, 2 };
public:

	int SecureFunction1()
	{
		for (i = 0; i < my_storage.size(); i++)
		{
			float result = my_storage[i] / my_storage[i + 1];
			std::cout << result << std::endl;
		}
		return 0; //if all goes well
	}

	int SecureFunction2()
	{
		for (i = 0; i <= my_storage.size(); i++)
		{
			std::cout << my_storage[i] << std::endl;
		}
		return 0;
	}

	int SecureFunction3()
	{
		FILE* fp;
			fopen_s(&fp, "txt.txt", "r");


			char* line = NULL;
			size_t len = 0;
			fgets(line, len, fp);
			printf("%s", line);
			fclose(fp);
			if (line)
				free(line);
			return 0;
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