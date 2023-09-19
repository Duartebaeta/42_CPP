#include "../incl/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "[WrongCat] default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &d) : WrongAnimal(d)
{
	*this = d;
	std::cout << "[WrongCat] copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &d)
{
	WrongAnimal::operator=(d);
	std::cout << "[WrongCat] copy assignemnt operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat sounds" << std::endl;
}