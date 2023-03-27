#include "../incl/Zombie.h"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *bigObj[N];
	Zombie *head = *bigObj;

	for (int counter = 0; counter < N; counter++)
		bigObj[counter] = new Zombie(name);
	return head;
}