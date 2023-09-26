#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/Intern.hpp"

int main(void)
{
	{
		std::cout << "\e[1;35m===========Constructing===========\033[0m" << std::endl;
		Intern  someRandomIntern;
		AForm* rrf;
		Bureaucrat tio(10, "ze");
		std::cout << "\e[1;35m===========Testing===========\033[0m" << std::endl;
		try {
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *rrf;
			rrf->beSigned(tio);
			tio.executeForm(*rrf);
			delete rrf;
		}
		catch (std::exception &e) {
			e.what();
		}
		try {
			rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
			std::cout << *rrf;
			rrf->beSigned(tio);
			tio.executeForm(*rrf);
			delete rrf;
		}
		catch (std::exception &e) {
			e.what();
		}
		std::cout << "\e[1;35m===========Destructing===========\033[0m" << std::endl;
	}

}