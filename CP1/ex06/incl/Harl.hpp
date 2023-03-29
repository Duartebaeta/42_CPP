#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

typedef std::string str;

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	void (Harl::*funcPtrArray[4])();
	str levels[4];
public:
	Harl(/* args */);
	~Harl();
	void complain( str complain );
};

#endif