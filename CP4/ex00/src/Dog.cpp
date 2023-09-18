#include "../incl/Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "[Dog] default constructor called" << std::endl;
}

Dog::Dog(const Dog &d) : Animal(d)
{
	*this = d;
	std::cout << "[Dog] copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &d)
{
	Animal::operator=(d);
	std::cout << "[Dog] copy assignemnt operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}