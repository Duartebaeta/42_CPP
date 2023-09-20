#include "../incl/AForm.hpp"

//Canonical
AForm::AForm()
	: name("Default"),
	is_signed(false),
	sign_grade(150),
	exec_grade(150),
	target("Default")
{
	std::cout << "[AForm] default constructor called" << std::endl;
}
AForm::AForm(const str name, const int sign, const int exec, const str target)
	:	name(name),
		is_signed(false),
		sign_grade(validate_grade(sign)),
		exec_grade(validate_grade(exec)),
		target(target)
{
	std::cout << "[AForm] parameter constructor called" << std::endl;
}
AForm::AForm(const AForm& copy)
	:	name(copy.name),
		sign_grade(copy.sign_grade),
		exec_grade(copy.exec_grade) 
{
	*this = copy;
	std::cout << "[AForm] copy constructor called" << std::endl;
}
AForm&	AForm::operator=(const AForm& copy)
{
	this->is_signed = copy.is_signed;
	std::cout << "[AForm] copy assignment operator called" << std::endl;
	return (*this);
}
AForm::~AForm() { std::cout << "[AForm] destructor called" << std::endl; }


//Helper methods
int	AForm::validate_grade(const int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	return (grade);
}

//Getters
str			AForm::getName() const { return (this->name); }
bool		AForm::getSignBool() const { return (this->is_signed); }
int			AForm::getSignGrade() const { return (this->sign_grade); }
int			AForm::getExecGrade() const { return (this->exec_grade); }
str			AForm::getTarget() const { return (this->target); }

//Setters
void	AForm::setSignBool(bool sign) { this->is_signed = sign; }

//Execption classes
const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade too low!";
}

const char* AForm::FormNotSigned::what() const throw(){
	return "Form needs to be signed before being executed!";
}

//Operator Overload
std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << " requires grade level " << form.getSignGrade() << " to sign and grade level "
<< form.getExecGrade() << " to execute, it " << (form.getSignBool() ? "has been signed already" : "has not been signed yet") << std::endl;
	return os;
}

//Class Functions
void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->sign_grade)
	{
		this->is_signed = true;
		this->signForm(b);
	}
	else
		throw AForm::GradeTooLowException();
}

void	AForm::signForm(const Bureaucrat& b)
{
	if (this->is_signed)
		std::cout << b.getName() << " signed " << this->name << std::endl;
	else
		std::cout << b.getName() << " couldn't sign " << this->name << " because his grade was too low";
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->is_signed)
	{
		if (this->exec_grade >= executor.getGrade())
			this->formAction();
		else
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::FormNotSigned();
}