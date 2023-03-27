#include "../incl/Weapon.hpp"

Weapon::Weapon(str type)
{
	this->_type = type;
}

Weapon::~Weapon(){}

void	Weapon::setType(str newType)
{
	this->_type = newType;
}

const str&	Weapon::getType()
{
	str& typeREF = this->_type;
	return typeREF;
}