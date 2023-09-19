#include "../incl/FragTrap.hpp"

int main()
{
    // Tests for FragTrap
    // Create an object using the default constructor
    FragTrap frag1;
    std::cout << "Name: " << frag1.get_name() << ", Hit Points: " << frag1.getHitPoints() << std::endl;

    // Create an object using the parameterized constructor
    FragTrap frag2("Frag2");
    std::cout << "Name: " << frag2.get_name() << ", Hit Points: " << frag2.getHitPoints() << std::endl;

    // Test attack method (inherited but should behave as per base class)
    frag1.attack("Enemy1");
    frag2.attack("Enemy2");

    // Test the new method specific to FragTrap
    frag1.highFivesGuys();
    frag2.highFivesGuys();

    // Test takeDamage (inherited from ClapTrap)
    frag1.takeDamage(-30);
    frag2.takeDamage(40);

    // Test beRepaired (inherited from ClapTrap)
    frag1.beRepaired(-10);
    frag2.beRepaired(20);

    // Test copy constructor
    FragTrap frag3(frag2);
    frag3.attack("Enemy3");

    // Test assignment operator
    frag1 = frag2;
    frag1.attack("NewEnemy1");

    // Destructor will be called automatically for frag1, frag2, and frag3
    return 0;
}
