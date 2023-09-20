#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"

int main(void)
{
	{
		try{
			std::cout << "\e[1;35m===========Constructing===========\033[0m" << std::endl;
			Bureaucrat exec(12, "execer");
			Bureaucrat signer(12, "signer");
			ShrubberyCreationForm A("ze manel");
			std::cout << "\e[1;35m===========Testing===========\033[0m" << std::endl;
			std::cout << A;
			exec.decrementGrade();
			signer.decrementGrade();
			A.beSigned(signer);
			std::cout << A;
			A.execute(exec);
			std::cout << "\e[1;35m===========Destructing===========\033[0m" << std::endl;
		}
		catch (std::exception &error){std::cout << error.what() << std::endl;}

	}
	{
		try{
			std::cout << "\e[1;35m===========Constructing===========\033[0m" << std::endl;
			Bureaucrat exec(45, "execer");
			Bureaucrat signer(72, "signer");
			RobotomyRequestForm A("roboto");
			std::cout << "\e[1;35m===========Testing===========\033[0m" << std::endl;
			std::cout << A;
			A.beSigned(signer);
			std::cout << A;
			A.execute(exec);
			std::cout << "\e[1;35m===========Destructing===========\033[0m" << std::endl;
		}
		catch (std::exception &error){std::cout << error.what() << std::endl;}
		
	}
	{
		try{
			std::cout << "\e[1;35m===========Constructing===========\033[0m" << std::endl;
			Bureaucrat exec(6 ,"execer");
			Bureaucrat signer(4, "signer");
			PresidentialPardonForm A("roboto");
			std::cout << "\e[1;35m===========Testing===========\033[0m" << std::endl;
			std::cout << A;
			//A.beSigned(signer);
			//std::cout << A;
			A.beSigned(exec);
			exec.incrementGrade();
			exec.executeForm(A);
			//A.execute(exec);
			std::cout << "\e[1;35m===========Destructing===========\033[0m" << std::endl;
		}
		catch (std::exception &error){std::cout << error.what() << std::endl;}	
	}

}