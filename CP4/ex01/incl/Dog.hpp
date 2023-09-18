#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"
#include <iostream>

class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog &d);
		Dog &operator=(const Dog &d);
		~Dog();
		virtual void makeSound() const;
		Brain*	getBrain();
};

#endif