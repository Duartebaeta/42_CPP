#include "../incl/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, "Default")
{
	std::cout << "[ShrubberyCreationForm] default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(str target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "[ShrubberyCreationForm] parameter constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	*this = copy;
	std::cout << "[ShrubberyCreationForm] copy constructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	AForm::operator=(copy);
	std::cout << "[ShrubberyCreationForm] copy assignment operator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] destructor called" << std::endl;
}

void	ShrubberyCreationForm::formAction() const
{
	std::ofstream	outfile;
	str				outfilename;

	outfilename = this->getTarget().append("_shrubbery");
	outfile.open(outfilename.c_str());
	if (outfile.is_open())
	{
		outfile << "        ^^                  ^^         " << std::endl;
		outfile << "      ^^^^^               ^^^^^        " << std::endl;
		outfile << "    ^^^^^^^^^           ^^^^^^^^^      " << std::endl;
		outfile << "  ^^^^^^^^^^^^^       ^^^^^^^^^^^^^    " << std::endl;
		outfile << "^^^^^^^^^^^^^^^^^   ^^^^^^^^^^^^^^^^^^ " << std::endl;
		outfile << "       |||                 |||        " << std::endl;
		outfile << "       |||                 |||        " << std::endl;
		outfile << "       |||                 |||        " << std::endl;
	}
}
