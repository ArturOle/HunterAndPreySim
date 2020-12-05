#pragma once
#include <exception>


struct FileNotOpened : public std::exception
{
	const char* what() const throw ()
	{
		return "File Not Opened";
	}
};

