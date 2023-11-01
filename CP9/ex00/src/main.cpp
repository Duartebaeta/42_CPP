#include "../incl/BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		return 1;
	try {
		BitcoinExchange b(argv[1]);

		b.exchange();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 1;
}