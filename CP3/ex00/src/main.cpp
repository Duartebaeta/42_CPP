#include "../incl/ClapTrap.hpp"

int main()
{
    // Test default constructor and parameter constructor
    ClapTrap clap1;
    ClapTrap clap2("CLTP-2");

    // Test attack
    clap1.attack("Target1");
    clap2.attack("Target2");

    // Test takeDamage
    clap1.takeDamage(5);
    clap2.takeDamage(2);

    // Test beRepaired
    clap1.beRepaired(1);
    clap2.beRepaired(3);
	clap2.beRepaired(3);
	clap2.beRepaired(3);

    // Test copy constructor
    ClapTrap clap3(clap2);
    clap3.attack("Target3");

    // Test assignment operator
    clap1 = clap2;
    clap1.attack("NewTarget1");

    // Destructor will be called automatically for clap1, clap2, and clap3
    return 0;
}
