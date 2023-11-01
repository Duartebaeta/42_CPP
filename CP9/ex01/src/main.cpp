#include "../incl/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	RPN r;

	try {
		r.solve(argv[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 1;
}