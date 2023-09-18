#include "../incl/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "[WrongAnimal] default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	*this = a;
	std::cout << "[WrongAnimal] copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a)
{
	this->type = a.type;
	return *this;
	std::cout << "[WrongAnimal] copy assignment operator called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sounds" << std::endl;
}

void	WrongAnimal::setType(str type)
{
	this->type = type;
}

str		WrongAnimal::getType() const
{
	return this->type;
}