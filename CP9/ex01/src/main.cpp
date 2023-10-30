#include "../incl/RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	RPN r;

	r.solve(argv[1]);
	return 1;
}