#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "./WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &c);
		WrongCat &operator=(const WrongCat &c);
		~WrongCat();
		void makeSound() const;
};

#endif