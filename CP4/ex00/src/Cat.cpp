#include "../incl/Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "[Cat] default constructor called" << std::endl;
}

Cat::Cat(const Cat &d) : Animal(d)
{
	*this = d;
	std::cout << "[Cat] copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &d)
{
	Animal::operator=(d);
	std::cout << "[Cat] copy assignemnt operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miau Miau" << std::endl;
}