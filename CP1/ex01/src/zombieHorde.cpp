#include "../incl/Zombie.hpp"
#include <string>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *bigObj = new Zombie[N];

	for (int counter = 0; counter < N; counter++)
		bigObj[counter].set_name(name);
	return bigObj;
}