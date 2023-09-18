#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

typedef std::string str;

class Animal
{
	protected:
		str type;
	public:
		Animal();
		Animal(const Animal &a);
		Animal &operator=(const Animal &);
		virtual ~Animal();
		virtual void makeSound() const;
		void	setType(str new_type);
		str		getType() const;
};

#endif