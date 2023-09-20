#include "../incl/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Fred"), grade(150)
{
	std::cout << "[Bureaucrat] default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, str name) : name(name)
{
	this->grade = grade;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	std::cout << "[Bureaucrat] default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	*this = copy;
	std::cout << "[Bureaucrat] copy constructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->grade = copy.grade;
	std::cout << "[Bureaucrat] copy assigment operator called" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] destructor called" << std::endl;
}

str	Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade - 1 <= 0)
		throw GradeTooHighException();
	this->grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	this->grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low!";
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << " bureaucrat grade " << obj.getGrade() << std::endl;
	return os;
}