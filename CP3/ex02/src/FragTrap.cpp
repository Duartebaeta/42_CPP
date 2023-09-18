#include "../incl/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setmaxHit(100);
	std::cout << "Default constructor called, [FragTrap]" << std::endl;
}

FragTrap::FragTrap(str name) : ClapTrap(name)
{
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setmaxHit(100);
	std::cout << "Parameter constructor called, [FragTrap]" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft)
{
	*this = ft;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ft)
{
	ClapTrap::operator=(ft);
	std::cout << "FragTrap: Copy Assignment operator called" << std::endl;
	return(*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Default destructor called, [FragTrap]" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "I REQUEST THE HIGHEST OF FIVES" << std::endl;
}