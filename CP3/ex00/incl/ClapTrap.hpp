#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

typedef std::string str;

class ClapTrap
{
	private:
		str	name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_dmg;
		unsigned int	max_hit;
	public:
		ClapTrap();
		ClapTrap(str new_name);
		ClapTrap(const ClapTrap &ct);
		ClapTrap &operator=(const ClapTrap &ct);
		virtual ~ClapTrap();
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif