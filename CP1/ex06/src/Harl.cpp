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
}

Harl::~Harl()
{
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

void Harl::complain(str complain)
{
	int counter = 0;

	while(counter < 4 && complain.compare(this->levels[counter]) != 0)
		counter++;

	switch (counter)
	{
		case 4:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		default:
			for (int cc = counter; cc < 4; cc++)
			{
				std::cout << '[' << this->levels[cc] << ']' << std::endl;
				(*this.*funcPtrArray[cc])();
				std::cout << std::endl;
			}
			break;
	};
}