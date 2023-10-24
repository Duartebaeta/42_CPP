#pragma once

#include <iostream>
#include "./Bureaucrat.hpp"

typedef std::string str;

class Bureaucrat;

class Form
{
	private:
		const str	name;
		bool		is_signed;
		const int	sign_grade;
		const int	exec_grade;
	public:
		//Canonic
		Form();
		Form(const str name, const int sign_grade, const int exec_grade);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();

		//Getters
		const str	getName() const;
		bool		getSignBool() const;
		int	getSignGrade() const;
		int	getExecGrade() const;

		//Setters
		void		setSignBool(bool sign);

		//helper methods
		int	validate_grade(const int grade);

		//Class functions
		void		beSigned(const Bureaucrat& b);

		//Exception classes
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream &os, const Form &form);