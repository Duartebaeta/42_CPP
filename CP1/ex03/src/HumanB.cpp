#include "../incl/HumanB.hpp"

HumanB::HumanB(str name) : _name(name)
{
	std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}

void HumanB::attack()
{
	if (!this->_weapon)
		std::cout << this->_name << " attacks with their......fists? Idk" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}