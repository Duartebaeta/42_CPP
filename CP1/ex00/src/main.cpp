#include "../incl/Zombie.hpp"

int main()
{
	Zombie *obj = newZombie("Xavier");
	obj->announce();
	Zombie n("Boo");
	n.announce();
	randomChump("Edgar");
	delete obj;
}