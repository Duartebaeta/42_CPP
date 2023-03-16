#include "../incl/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->cycle = -1;
	this->contacts = 0;
}

void PhoneBook::Add(void)
{
	this->cycle++, this->contacts++;
	if (this->cycle > 7)
		this->cycle = 0;
	if (this->contacts > 8)
		this->contacts = 8;
	str arr[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};
	for (int counter = 0; counter < 5; counter++)
	{
		str	input = "";
		while (input.length() == 0)
		{
			std::cout << "Please enter contact's " + arr[counter] + "-> ";
			getline(std::cin, input);
		}
		switch (counter)
		{
			case 0:
				this->list[this->cycle].AddFirstName(input);
				break;
			case 1:
				this->list[this->cycle].AddLastName(input);
				break;
			case 2:
				this->list[this->cycle].AddNickName(input);
				break;
			case 3:
				this->list[this->cycle].AddPhoneNumber(input);
				break;
			case 4:
				this->list[this->cycle].AddDarkestSecret(input);
				break;
		}
	}
}

void PhoneBook::Search(void)
{
	if (this->cycle == -1)
	{
		std::cout << "You have no saved contacts, first create one using the command ADD" << std::endl;
		return;
	}

	str	border = "--------------------------------------------------";

	for (int contacts = 0; contacts < (int)this->contacts; contacts++)
	{
		std::cout << border << std::endl << "|         " << contacts << "|";
		for (int counter = 0; counter < 3; counter++)
			this->list[contacts].print_info(counter);
		std::cout << std::endl;
	}
	std::cout << border << std::endl;

	str input;
	int index;
	while (input.length() == 0)
	{
		std::cout << "Select contact index to display information -> ";
		getline(std::cin, input);
		index = input[0] - '0';
		if (std::isdigit(input[0]) && index != 9 && index < this->contacts)
			break;
		std::cout << "Invalid index" << std::endl;
		input = "";
	}
	this->list[input[0] - '0'].print_contact();
}