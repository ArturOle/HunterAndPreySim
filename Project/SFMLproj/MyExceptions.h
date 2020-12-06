#pragma once
#include <exception>


class FileNotOpened : public std::exception
{
public:
	const char* what() const throw ()
	{
		return "File Not Opened";
	}
};

