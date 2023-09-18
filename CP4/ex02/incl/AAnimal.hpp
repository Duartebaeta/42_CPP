#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

typedef std::string str;

class AAnimal
{
	protected:
		str type;
	public:
		AAnimal();
		AAnimal(const AAnimal &a);
		AAnimal &operator=(const AAnimal &);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		void	setType(str new_type);
		str		getType() const;
};

#endif