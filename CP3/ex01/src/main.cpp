#include "../incl/ScavTrap.hpp"

int main()
{
    // Create an object using default constructor
    ScavTrap scav1;
    std::cout << "Name: " << scav1.get_name() << ", Hit Points: " << scav1.getHitPoints() << std::endl;

    // Create an object using the parameterized constructor
    ScavTrap scav2("Scav2");
    std::cout << "Name: " << scav2.get_name() << ", Hit Points: " << scav2.getHitPoints() << std::endl;

    // Test attack method (inherited but overridden)
    scav1.attack("Enemy1");
    scav2.attack("Enemy2");

    // Test the new method specific to ScavTrap
    scav1.guardGate();
    scav2.guardGate();

    // Test takeDamage (inherited from ClapTrap)
    scav1.takeDamage(30);
    scav2.takeDamage(40);

    // Test beRepaired (inherited from ClapTrap)
    scav1.beRepaired(10);
    scav2.beRepaired(20);
	scav2.beRepaired(30);
	scav2.beRepaired(20);

    // Test copy constructor
    ScavTrap scav3(scav2);
    scav3.attack("Enemy3");

    // Test assignment operator
    scav1 = scav2;
    scav1.attack("NewEnemy1");

    // Destructor will be called automatically for scav1, scav2, and scav3
    return 0;
}