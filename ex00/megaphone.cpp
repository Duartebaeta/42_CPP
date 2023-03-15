#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int counter = 0; argv[i][counter]; counter++)
				std::cout << (char)std::toupper(argv[i][counter]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
