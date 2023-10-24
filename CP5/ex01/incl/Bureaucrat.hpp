#pragma once

#include <iostream>
#include "./Form.hpp"

typedef std::string str;

class Form;

class	Bureaucrat
{
	private:
		const str	name;
		int			grade;
	public:
		//Canonical
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat(void);
		Bureaucrat(int grade, str name);

		//Member functions
		str		getName(void) const;
		int		getGrade(void) const;
		void	incrementGrade(void);
		void	decrementGrade(void); 
		void	signForm(const Form &form) const;
		
		//Exception Classes
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
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);