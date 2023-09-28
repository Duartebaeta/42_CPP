#include "../incl/Serializer.hpp"


int main() {
	Data data1(42, 3.14, 'X');
	Data data2(99, 2.71, 'Y');

	std::cout << "Before Serialization:" << std::endl;
	std::cout << "data1: " << &data1 << ", data2: " << &data2 << std::endl;

	uintptr_t serialized1 = Serializer::serialize(&data1);
	uintptr_t serialized2 = Serializer::serialize(&data2);

	std::cout << "Serialized:" << std::endl;
	std::cout << "serialized1: " << serialized1 << ", serialized2: " << serialized2 << std::endl;

	Data* deserialized1 = Serializer::deserialize(serialized1);
	Data* deserialized2 = Serializer::deserialize(serialized2);

	std::cout << "After Deserialization:" << std::endl;
	std::cout << "deserialized1: " << deserialized1 << ", deserialized2: " << deserialized2 << std::endl;

	if(deserialized1 == &data1 && deserialized2 == &data2) {
		std::cout << "Serialization and deserialization were successful!" << std::endl;
	} else {
		std::cout << "Something went wrong." << std::endl;
	}

	return 0;
}