#include "../incl/Data.hpp"

Data::Data() : a(1), b(2.0), c('d')
{
	std::cout << "[Data] Default constructor called" << std::endl;
}

Data::Data(int a, double b, char c) : a(a), b(b), c(c)
{
	std::cout << "[Data] Parameter constructor called" << std::endl;
}

Data::Data(const Data &copy)
{
	*this = copy;
	std::cout << "[Data] Copy constructor called" << std::endl;
}

Data	&Data::operator=(const Data& copy)
{
	this->a = copy.a;
	this->b = copy.b;
	this->c = copy.c;
	std::cout << "[Data] Copy assignment operator called" << std::endl;
	return *this;
}

Data::~Data()
{
	std::cout << "[Data] Destructor called" << std::endl;
}