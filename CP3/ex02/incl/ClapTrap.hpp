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
		int max_hit;
	public:
		ClapTrap();
		ClapTrap(str new_name);
		ClapTrap(const ClapTrap &ct);
		ClapTrap &operator=(const ClapTrap &ct);
		virtual ~ClapTrap();
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		str	get_name();
		int	get_attack();
		void setName(str name);
		void setHitPoints(int hitpts);
		void setEnergyPoints(int energypts);
		void setAttackDamage(int attackpts);
		void setmaxHit(int health);
		int getHitPoints(void);
		int getEnergyPoints(void);
		int getAttackDamage(void);
		int getMaxHit(void);
};

#endif