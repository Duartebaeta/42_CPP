#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

typedef std::string str;

class Zombie
{
	private:
		str	name;

	public:
		Zombie(str name);
		~Zombie(void);
		void announce(void);
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif