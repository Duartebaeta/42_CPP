#include "../incl/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	hit_points = 10;
	energy_points = 10;
	attack_dmg = 0;
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(str new_name)
{
	this->name = new_name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_dmg = 0;
	std::cout << "Parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	*this = ct;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct)
{
	this->name = ct.name;
	this->hit_points = ct.hit_points;
	this->energy_points = ct.energy_points;
	this->attack_dmg = ct.attack_dmg;
	std::cout << "Copy assignment constructor called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_dmg << " points of damage!" << std::endl;
	this->energy_points -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " has taken " << amount << "points of damage!" << std::endl;
	this->hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " has been repaired for " << amount << " hit points!" << std::endl;
	this->hit_points += amount;
	this->energy_points -= 1;
}