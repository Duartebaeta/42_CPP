#include "../incl/Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "[Brain] copy constructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &copy)
{
	for (int counter = 0; counter < 100; counter++)
		this->ideas[counter] = copy.ideas[counter];
	std::cout << "[Brain] copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "[Brain] destructor called" << std::endl;
}
