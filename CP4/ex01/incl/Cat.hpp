#ifndef CAT_HPP
#define CAT_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"
#include <iostream>

class Cat : public Animal
{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(const Cat &c);
		Cat &operator=(const Cat &c);
		~Cat();
		virtual void makeSound() const;
		Brain*	getBrain();
};

#endif