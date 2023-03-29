#include "../incl/Harl.hpp"

int main(int argc, char const *argv[])
{
	Harl harl;

	if (argc != 2)
		return 1;
	harl.complain(argv[1]);
	return 0;
}


// int main()
// {
// 	Harl harl;
// 	str input = "";
// 	while (input != "exit")
// 	{
// 		getline(std::cin, input);
// 		harl.complain(input);
// 	}
// }