#pragma once

#include <iostream>
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
typedef std::string str;

class Intern
{
	private:
		str	formNames[3];
		typedef AForm *(Intern::*funcPtr)(str, str); // typedef for member function pointer
		funcPtr forms[4];
	public:
		Intern();
		Intern(const Intern& copy);
		Intern &operator=(const Intern& copy);
		~Intern();
		AForm	*makeForm(str name, str target);
		AForm	*createShrubbery(str name ,str target);
		AForm	*createRobotomy(str name ,str target);
		AForm	*createPresidential(str name ,str target);
		AForm	*invalidForm(str name ,str target);

		class InvalidFormName: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};