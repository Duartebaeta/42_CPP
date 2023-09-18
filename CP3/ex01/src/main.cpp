#include "../incl/ScavTrap.hpp"

int main()
{
	std::cout << "\e[1;35m---------------Constructing---------------\033[0m" << std::endl;
	ScavTrap c("daniginga");
	ScavTrap d("SIUUU");
	std::cout << "\e[1;35m---------------Testing---------------\033[0m" << std::endl;
	c.attack(d.get_name());
	d.takeDamage(c.getAttackDamage());
	d.guardGate();
	d.beRepaired(50);
	c.guardGate();
	d.attack(c.get_name());
	c.takeDamage(d.getAttackDamage());
	d.attack(c.get_name());
	c.takeDamage(d.getAttackDamage());
	d.attack(c.get_name());
	c.takeDamage(d.getAttackDamage());
	c.beRepaired(10);
	c.beRepaired(100);
	std::cout << "\e[1;35m---------------Deconstructing\033[0m---------------" << std::endl;
	return 0;
}