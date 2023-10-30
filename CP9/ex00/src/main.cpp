#include "../incl/BitcoinExchange.hpp"

int main()
{
	try {
		BitcoinExchange b("input.txt");

		b.exchange();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 1;
}