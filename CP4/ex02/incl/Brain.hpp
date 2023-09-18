#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		~Brain();
		std::string ideas[100];
		std::string	getIdea(int index);
		void	setIdea(int index, std::string idea);
};

#endif