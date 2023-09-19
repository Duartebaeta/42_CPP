#include "../incl/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->setHitPoints(100);
	this->setmaxHit(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "Default constructor called, [ScavTrap]" << std::endl;
}

ScavTrap::ScavTrap(str new_name) : ClapTrap(new_name)
{
	this->setName(new_name);
	this->setHitPoints(100);
	this->setmaxHit(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "Parameter constructor called, [ScavTrap]" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &src ): ClapTrap(src)
{
	*this = src;
	std::cout << "ScavTrap:" << this->get_name() << " copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap const &src)
{
	ClapTrap::operator=(src);
	std::cout << "ScavTrap: Copy Assignment operator called" << std::endl;
	return(*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Default destructor called, [ScavTrap]" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << this->get_name() << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->get_name() << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->get_name() << " is guarding the gate, YOU SHALL NOT PASS" << std::endl;
}