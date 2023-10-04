#include "../incl/Array.hpp"

int main() {
	try {
		Array<int> arr1(5);

		// Test assignment of values and retrieval
		for (unsigned int i = 0; i < arr1.size(); ++i) {
			arr1[i] = i * 10;
		}

		for (unsigned int i = 0; i < arr1.size(); ++i) {
			std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;
		}

		// Test size
		std::cout << "Size of arr1: " << arr1.size() << std::endl;

		// Test out-of-bounds access
		std::cout << "arr1[5] = " << arr1[5] << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// Test copy constructor and assignment
	Array<int> arr2(3);
	arr2 = Array<int>(2);
	arr2[0] = 100;
	arr2[1] = 200;

	Array<int> arr3(arr2); // Copy constructor
	arr3[0] = 50;

	std::cout << "arr2[0] = " << arr2[0] << ", arr2[1] = " << arr2[1] << std::endl;
	std::cout << "arr3[0] = " << arr3[0] << ", arr3[1] = " << arr3[1] << std::endl;

	return 0;
}
