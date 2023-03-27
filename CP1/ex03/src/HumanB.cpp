#include "../incl/HumanB.hpp"

HumanB::HumanB(str name)
{
	this->_name = name;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	// if (this->_weapon->getType().length() == 0)
	// 	std::cout << this->_name << " attacks with their......fists? Idk" << std::endl;
	// else
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}