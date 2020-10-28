#pragma once
#include <fstream>
#include <vector>


template <typename T1>
class CompNumb
{
protected:
	T1 real_number;
	T1 imag_number;
public:
	CompNumb(std::vector<T1> pair_in);
	
	std::ostream& operator<<(std::ostream& output);

	~CompNumb() = default;
};


template<typename R>
inline CompNumb<R>::CompNumb(std::vector<R> pair_in)
{
	this->real_number = pair_in[0];
	this->imag_number = pair_in[1];
}


template<typename R>
inline std::ostream& CompNumb<R>::operator<<(std::ostream& output)
{
	output << "Complex number: " << this->real_number << "+i" << this->imag_number << std::endl;;
	return output;
}
