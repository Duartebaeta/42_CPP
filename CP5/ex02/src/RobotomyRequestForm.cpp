#include "../incl/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "Default")
{
	std::cout << "[RobotomyRequestForm] default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(str target) : AForm("RobotomyRequestForm", 25, 5, target)
{
	std::cout << "[RobotomyRequestForm] parameter constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
	*this = copy;
	std::cout << "[RobotomyRequestForm] copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	AForm::operator=(copy);
	std::cout << "[RobotomyRequestForm] copy assignment operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] destructor called" << std::endl;
}

void	RobotomyRequestForm::formAction() const
{
	str successful = " has been robotomized successfully!";
	str unsuccessfuly = " has a thick freaking skull, no robotomy for them...";

	std::cout << "* VERY QUIET, TOTALLY NOT TOTURING DRILL SOUNDS *" << std::endl;
	std::cout << "* VERY QUIET, TOTALLY NOT TOTURING DRILL SOUNDS *" << std::endl;
	int	random_number = rand();

	int min = 0, max = 1;
	random_number = min + (random_number % (max - min + 1));
	std::cout << this->getTarget() << (random_number == 0 ? successful : unsuccessfuly) << std::endl;
}