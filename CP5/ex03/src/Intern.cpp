#include "../incl/Intern.hpp"
#include <string.h>

Intern::Intern()
{
	this->formNames[0] = "shrubbery request";
	this->formNames[1] = "robotomy request";
	this->formNames[2] = "presidential request";
	this->forms[0] = &Intern::createShrubbery;
	this->forms[1] = &Intern::createRobotomy;
	this->forms[2] = &Intern::createPresidential;
	this->forms[3] = &Intern::invalidForm;
	std::cout << "[Intern] default constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
	std::cout << "[Intern] copy constructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& copy)
{
	(void)copy;
	std::cout << "[Intern] copy assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "[Intern] destructor called" << std::endl;
}

AForm *Intern::createShrubbery(str name ,str target)
{
	std::cout << "Intern creates " << name << std::endl;
	ShrubberyCreationForm *ret = new ShrubberyCreationForm(target);
	return (ret);
}
AForm *Intern::createRobotomy(str name ,str target)
{
	std::cout << "Intern creates " << name << std::endl;
	RobotomyRequestForm *ret = new RobotomyRequestForm(target);
	return (ret);
}
AForm *Intern::createPresidential(str name ,str target)
{
	std::cout << "Intern creates " << name << std::endl;
	PresidentialPardonForm *ret = new PresidentialPardonForm(target);
	return (ret);
}
AForm *Intern::invalidForm(str name ,str target)
{
	std::cout << "Invalid form name " << name << " targeting " << target << std::endl;
	throw (Intern::InvalidFormName());
}

AForm	*Intern::makeForm(str name, str target)
{
	int	counter = 0;
	while (name != this->formNames[counter] && counter < 3)
		counter++;
	try {
		return (this->*forms[counter])(name, target);
	}
	catch (std::exception &e) {
		throw;
	}
}

const char* Intern::InvalidFormName::what() const throw()
{
	return "Invalid form name";
}