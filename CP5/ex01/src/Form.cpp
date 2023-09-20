#include "../incl/Form.hpp"

//Canonical
Form::Form()
	: name("Default"),
	is_signed(false),
	sign_grade(150),
	exec_grade(150)
{
	std::cout << "[Form] default constructor called" << std::endl;
}
Form::Form(const str name, const int sign, const int exec)
	:	name(name),
		is_signed(false),
		sign_grade(validate_grade(sign)),
		exec_grade(validate_grade(exec))
{
	std::cout << "[Form] parameter constructor called" << std::endl;
}
Form::Form(const Form& copy)
	:	name(copy.name),
		sign_grade(copy.sign_grade),
		exec_grade(copy.exec_grade) 
{
	*this = copy;
	std::cout << "[Form] copy constructor called" << std::endl;
}
Form&	Form::operator=(const Form& copy)
{
	this->is_signed = copy.is_signed;
	std::cout << "[Form] copy assignment operator called" << std::endl;
	return (*this);
}
Form::~Form() { std::cout << "[Form] destructor called" << std::endl; }


//Helper methods
int	Form::validate_grade(const int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	return (grade);
}

//Getters
const str	Form::getName() const { return (this->name); }
bool		Form::getSignBool() const { return (this->is_signed); }
int	Form::getSignGrade() const { return (this->sign_grade); }
int	Form::getExecGrade() const { return (this->exec_grade); }

//Setters
void	Form::setSignBool(bool sign) { this->is_signed = sign; }

//Execption classes
const char* Form::GradeTooHighException::what() const throw(){
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade too low!";
}

//Operator Overload
std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << " requires grade level " << form.getSignGrade() << " to sign and grade level "
<< form.getExecGrade() << " to execute, it " << (form.getSignBool() ? "has been signed already" : "has not been signed yet") << std::endl;
	return os;
}

//Class Functions
void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->sign_grade)
	{
		this->is_signed = true;
		this->signForm(b);
	}
	else
		throw Form::GradeTooLowException();
}

void	Form::signForm(const Bureaucrat& b)
{
	if (this->is_signed)
		std::cout << b.getName() << " signed " << this->name << std::endl;
	else
		std::cout << b.getName() << " couldn't sign " << this->name << " because his grade was too low";
}