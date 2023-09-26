#pragma once

#include <iostream>
#include "./AForm.hpp"

typedef std::string str;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(str target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		virtual ~RobotomyRequestForm();
		virtual void	formAction(void) const;
};
