#include "../incl/Zombie.h"

int main()
{
	Zombie *obj = newZombie("Xavier");
	obj->announce();
	randomChump("Edgar");
}