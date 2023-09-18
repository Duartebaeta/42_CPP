#include "../incl/Weapon.hpp"

Weapon::Weapon(str type) : _type(type)
{
	std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;
}

void	Weapon::setType(str newType)
{
	this->_type = newType;
}

const str&	Weapon::getType()
{
	str& typeREF = this->_type;
	return typeREF;
}