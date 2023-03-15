#include "../incl/PhoneBook.hpp"
#include "../incl/Contact.hpp"

int main()
{
	PhoneBook	pb;
	str			input;

	while (1)
	{
		std::cout << "->";
		getline(std::cin, input);
		if (input == "EXIT")
			return 0;
		else if (input == "ADD")
			pb.Add();
	}
	return 0;
}
