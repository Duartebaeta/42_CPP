#include "../incl/Contact.hpp"

void	Contact::print_info(int selector)
{
	str	info;
	switch (selector)
	{
	case 0:
		info = this->firstname;
		break;
	case 1:
		info = this->lastname;
		break;
	case 2:
		info = this->nickname;
		break;
	}
	if (info.length() == 10)
		std::cout << info << "|";
	else if (info.length() > 10)
	{
		for (int counter = 0; counter <= 8; counter++)
			std::cout << info[counter];
		std::cout << ".|";
	}
	else
	{
		int	sub = 0;
		for (int counter = 0; counter < 10; counter++)
		{
			if (10 - counter > (int)info.length())
				std::cout << " ";
			else
				std::cout << info[sub++];
		}
		std::cout << "|";
	}
}

void	Contact::print_contact(void)
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