#include "../incl/Zombie.h"

int main()
{
	Zombie *head = zombieHorde(9, "Edd");
	
	delete[] head;
	return 0;
}