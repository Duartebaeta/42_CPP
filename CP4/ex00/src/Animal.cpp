#include "../incl/Animal.hpp"

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "[Animal] default constructor called" << std::endl;
}

Animal::Animal(const Animal &a)
{
	*this = a;
	std::cout << "[Animal] copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &a)
{
	this->type = a.type;
	std::cout << "[Animal] copy assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "[Animal] destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal sounds" << std::endl;
}

void	Animal::setType(str type)
{
	this->type = type;
}

str		Animal::getType() const
{
	return this->type;
}