#include "../incl/FragTrap.hpp"

int main()
{
	{
		std::cout << "\e[1;35m---------------ScavTrap Test---------------\033[0m" << std::endl;
		std::cout << "\e[1;35m---------------Constructing---------------\033[0m" << std::endl;
		ScavTrap c("Scavi");
		ScavTrap d("DVAI");
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
		std::cout << "\e[1;35m---------------Deconstructing\033[0m---------------" << std::endl;
	}
	{
		std::cout << "\e[1;35m---------------FragTrap Test---------------\033[0m" << std::endl;
		std::cout << "\e[1;35m---------------Constructing---------------\033[0m" << std::endl;
		FragTrap a("sapinho");
		FragTrap b("ppnc");
		std::cout << "\e[1;35m---------------Testing---------------\033[0m" << std::endl;
		a.highFivesGuys();
		a.attack(b.get_name());
		b.takeDamage(b.getAttackDamage());
		b.beRepaired(b.getAttackDamage());
		b.attack(a.get_name());
		a.takeDamage(b.getAttackDamage());
		b.attack(a.get_name());
		a.takeDamage(b.getAttackDamage());
		b.attack(a.get_name());
		a.takeDamage(b.getAttackDamage());
		b.attack(a.get_name());
		a.takeDamage(b.getAttackDamage());
		b.attack(a.get_name());
		a.takeDamage(b.getAttackDamage());
		std::cout << "\e[1;35m---------------Deconstructing\033[0m---------------" << std::endl;
	}
}