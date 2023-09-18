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
	this->max_hit = 10;
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
	std::cout << "ClapTrap " << name << " has taken " << amount << " points of damage!" << std::endl;
	this->hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
		return ;
	}
	else if (this->hit_points >= max_hit)
	{
		std::cout << "ClapTrap " << name << " is already fully repaired!" << std::endl;
		return ;
	}
	else if (this->hit_points + (int)amount >= this->max_hit)
	{
		std::cout << "ClapTrap " << name << " can't fathom so many repairs" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " has been repaired for " << amount << " hit points!" << std::endl;
	this->hit_points += amount;
	this->energy_points -= 1;
}

str	ClapTrap::get_name()
{
	return this->name;
}

int	ClapTrap::getAttackDamage()
{
	return this->attack_dmg;
}

int ClapTrap::getEnergyPoints()
{
	return this->energy_points;
}

int ClapTrap::getHitPoints()
{
	return this->hit_points;
}

int ClapTrap::getMaxHit()
{
	return this->max_hit;
}

void ClapTrap::setAttackDamage(int dmg)
{
	this->attack_dmg = dmg;
}

void ClapTrap::setEnergyPoints(int energy)
{
	this->energy_points = energy;
}

void ClapTrap::setHitPoints(int hit)
{
	this->hit_points = hit;
}

void ClapTrap::setmaxHit(int max)
{
	this->max_hit = max;
}

void ClapTrap::setName(str name)
{
	this->name = name;
}