#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(str new_name);
		ScavTrap(const ScavTrap &st);
		ScavTrap &operator=(const ScavTrap &st);
		~ScavTrap();
		virtual void attack(const std::string& target);
		void guardGate();
};

#endif