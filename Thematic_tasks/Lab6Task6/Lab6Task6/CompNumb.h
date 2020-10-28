#pragma once
#include <fstream>


template <typename R, typename I>
class CompNumb
{
protected:
	R real_number;
	I imag_number;
public:
	CompNumb(R real_in, I imag_in);

	std::ostream& operator<<(std::ostream& output);

	~CompNumb() = default;
};


template<typename R, typename I>
inline CompNumb<R, I>::CompNumb(R real_in, I imag_in)
{
	this->real_number = real_in;
	this->imag_number = imag_in;
}


template<typename R, typename I>
inline std::ostream& CompNumb<R, I>::operator<<(std::ostream& output)
{
	output << "Complex number: " << this->real_number << "+i" << this->imag_number << std::endl;;
	return output;
}
