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
	void invalid_arg(void);

	str levels[4];
	void (Harl::*funcPtrArray[5])();
public:
	Harl(/* args */);
	~Harl();
	void complain( str level );
};

#endif