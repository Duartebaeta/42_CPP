#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

typedef std::string str;

class WrongAnimal
{
	protected:
		str type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &a);
		WrongAnimal &operator=(const WrongAnimal &);
		~WrongAnimal();
		void makeSound() const;
		void	setType(str new_type);
		str		getType() const;
};

#endif