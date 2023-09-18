#include "../incl/Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "[Cat] default constructor called" << std::endl;
}

Cat::Cat(const Cat &d) : AAnimal(d)
{
	this->brain = new Brain();
	*this = d;
	std::cout << "[Cat] copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &d)
{
	AAnimal::operator=(d);
	*this->brain = *d.brain;
	std::cout << "[Cat] copy assignemnt operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "[Cat] destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miau Miau" << std::endl;
}

Brain*	Cat::getBrain()
{
	return this->brain;
}