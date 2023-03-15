#include "../incl/Contact.hpp"

void	Contact::print_info(void)
{
	std::cout << this->firstname << std::endl;
	std::cout << this->lastname << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->phone << std::endl;
	std::cout << this->ds << std::endl;
}

void Contact::AddFirstName(str firstname)
{
	this->firstname = firstname;
}

void Contact::AddLastName(str lastname)
{
	this->lastname = lastname;
}

void Contact::AddNickName(str nickname)
{
	this->nickname = nickname;
}

void Contact::AddPhoneNumber(str phone)
{
	this->phone = phone;
}

void Contact::AddDarkestSecret(str ds)
{
	this->ds = ds;
}