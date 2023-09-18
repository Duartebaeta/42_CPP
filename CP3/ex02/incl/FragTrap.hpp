#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(str new_name);
		FragTrap(const FragTrap &st);
		FragTrap &operator=(const FragTrap &st);
		~FragTrap();
		void highFivesGuys(void);
};

#endif