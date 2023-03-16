#include "../incl/PhoneBook.hpp"
#include "../incl/Contact.hpp"

int main()
{
	PhoneBook	pb;
	str			input;

	while (1)
	{
		std::cout << "Insert one of the following commands" << std::endl << "ADD, SEARCH, EXIT" << std::endl << "->";
		getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			system("clear");
			pb.Add();
		}
		else if (input == "SEARCH")
		{
			system("clear");
			pb.Search();
		}
	}
	return 0;
}
