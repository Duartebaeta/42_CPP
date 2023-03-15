#include "../incl/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->cycle = 0;
}

void PhoneBook::Add(void)
{
	str arr[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
	for (int counter = 0; counter < 5; counter++)
	{
		str	input = "";
		while (input.length() == 0)
		{
			std::cout << "Please enter" + arr[counter] + "->";
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