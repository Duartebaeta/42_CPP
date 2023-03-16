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
