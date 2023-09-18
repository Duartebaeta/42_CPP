#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

typedef std::string str;

class ClapTrap
{
	private:
		str	name;
		int	hit_points;
		int	energy_points;
		int	attack_dmg;
	public:
		ClapTrap();
		ClapTrap(str name);
		ClapTrap(const ClapTrap &ct);
		ClapTrap &operator=(const ClapTrap &ct);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif