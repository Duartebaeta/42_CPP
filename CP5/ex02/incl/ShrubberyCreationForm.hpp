#pragma once

#include <iostream>
#include "./AForm.hpp"

typedef std::string str;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(str target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		virtual void	formAction(void) const;
};
