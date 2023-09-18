#include "../incl/Zombie.hpp"

Zombie::Zombie(str name)
{
	this->name = name;
	std::cout << "A zombie has risen from the ground" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has gone back into the ground" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}