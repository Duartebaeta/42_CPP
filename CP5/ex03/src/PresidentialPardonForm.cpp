#include "../incl/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "Default")
{
	std::cout << "[PresidentialPardonForm] default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(str target) : AForm("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "[PresidentialPardonForm] parameter constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	*this = copy;
	std::cout << "[PresidentialPardonForm] copy constructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	AForm::operator=(copy);
	std::cout << "[PresidentialPardonForm] copy assignment operator called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] destructor called" << std::endl;
}

void	PresidentialPardonForm::formAction() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
