#include "Reader.h"


Reader::Reader(std::string filename_in)
{
	this->filename = filename_in;
	this->quantity_lines = this->num_of_lines();
}


int Reader::num_of_lines()
{
	std::ifstream inFile(filename);
	int num = std::count(std::istreambuf_iterator<char>(inFile),
					     std::istreambuf_iterator<char>(), '\n') + 1;
	return num;
}
