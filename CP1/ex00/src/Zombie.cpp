#include "../incl/Zombie.hpp"

Zombie::Zombie(str name)
{
	this->name = name;
}

Zombie::~Zombie()
{
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}