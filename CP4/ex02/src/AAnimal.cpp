#include "../incl/AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "AAnimal";
	std::cout << "[AAnimal] default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a)
{
	*this = a;
	std::cout << "[AAnimal] copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &a)
{
	this->type = a.type;
	std::cout << "[AAnimal] copy assignment operator called" << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal] destructor called" << std::endl;
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal sounds" << std::endl;
}

void	AAnimal::setType(str type)
{
	this->type = type;
}

str		AAnimal::getType() const
{
	return this->type;
}