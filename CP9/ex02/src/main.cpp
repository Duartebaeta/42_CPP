#include "../incl/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Not enough arguments: " << argc << std::endl;
		return 1;
	}

	PmergeMe	pm;

	try {
		pm.sort(argv);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}