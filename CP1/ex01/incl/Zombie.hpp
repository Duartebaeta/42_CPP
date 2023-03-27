#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

typedef std::string str;

class Zombie
{
	private:
		str	name;

	public:
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void set_name(str name);
};


#endif