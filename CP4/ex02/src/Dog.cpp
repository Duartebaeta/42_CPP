#include "../incl/Dog.hpp"

Dog::Dog() : AAnimal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "[Dog] default constructor called" << std::endl;
}

Dog::Dog(const Dog &d) : AAnimal(d)
{
	this->brain = new Brain();
	*this = d;
	std::cout << "[Dog] copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &d)
{
	AAnimal::operator=(d);
	*this->brain = *d.brain;
	std::cout << "[Dog] copy assignemnt operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "[Dog] destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

Brain*	Dog::getBrain()
{
	return this->brain;
}