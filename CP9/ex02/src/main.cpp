#include "../incl/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	PmergeMe	pm;

	try {
		pm.sort(argv[1]);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}