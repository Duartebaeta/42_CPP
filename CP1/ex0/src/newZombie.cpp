#include "../incl/Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie *newZz = new Zombie(name);
	return newZz;
}