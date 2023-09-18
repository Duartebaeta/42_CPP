#include "../incl/Zombie.hpp"

int main()
{
	int	zombie_num = 9;

	Zombie *head = zombieHorde(zombie_num, "Edd");

	for (int counter = 0; counter < zombie_num; counter++)
		head[counter].announce();
	delete[] head;
	return 0;
}