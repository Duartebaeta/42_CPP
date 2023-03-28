#include "../incl/Harl.hpp"

int main()
{
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("");
	harl.complain("D");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("     ");
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