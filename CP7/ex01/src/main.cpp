#include "../incl/iter.hpp"


int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	iter<int>(intArray, 5, &test);

	iter<double>(doubleArray, 5, &test);

	iter<double>(doubleArray, 5, printDouble);

	return 0;
}