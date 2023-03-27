#include "../incl/Zombie.h"

int main()
{
	Zombie *head = zombieHorde(10, "Edd");
	head->announce();
}