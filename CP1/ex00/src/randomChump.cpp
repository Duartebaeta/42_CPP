#include "../incl/Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie tempZz = Zombie(name);
	tempZz.announce();
}