#pragma once

#include <iostream>
#include <cstdlib>

typedef std::string str;

class Base
{
	public:
		virtual ~Base() {};
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
