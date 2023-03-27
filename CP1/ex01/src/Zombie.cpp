#include "../incl/Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie()
{
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(str name)
{
	this->name = name;
}