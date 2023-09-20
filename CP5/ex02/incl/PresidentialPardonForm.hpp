#pragma once

#include <iostream>
#include "./AForm.hpp"

typedef std::string str;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(str target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		virtual void	formAction(void) const;
};
