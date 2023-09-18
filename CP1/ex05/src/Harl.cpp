#include "../incl/Harl.hpp"

Harl::Harl()
{
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
	this->funcPtrArray[0] = &Harl::debug;
	this->funcPtrArray[1] = &Harl::info;
	this->funcPtrArray[2] = &Harl::warning;
	this->funcPtrArray[3] = &Harl::error;
	this->funcPtrArray[4] = &Harl::invalid_arg;
	std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Harl destructor called" << std::endl;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::invalid_arg()
{
	std::cout << "Invalid complain argument!" << std::endl;
}

void Harl::complain( str level )
{
	int counter = 0;

	while (counter < 4 && level.compare(this->levels[counter]))
		counter++;
	(*this.*funcPtrArray[counter])();
}