#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "./Bureaucrat.hpp"

class Bureaucrat;

typedef std::string str;

class AForm
{
	private:
		const str	name;
		bool		is_signed;
		const int	sign_grade;
		const int	exec_grade;
		const str	target;
	public:
		//Canonic
		AForm();
		AForm(const str name, const int sign_grade, const int exec_grade, const str target);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();

		//Getters
		str	getName() const;
		bool		getSignBool() const;
		int	getSignGrade() const;
		int	getExecGrade() const;
		str	getTarget() const;

		//Setters
		void		setSignBool(bool sign);

		//helper methods
		int	validate_grade(const int grade);

		//Class functions
		void			beSigned(const Bureaucrat& b);
		void			signForm(const Bureaucrat& b);
		void			execute(Bureaucrat const & executor) const;
		virtual void	formAction(void) const = 0;

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

		class FormNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream &os, const AForm &form);