#include <iostream>
typedef std::string str;

int main()
{
	str original = "HI THIS IS BRAIN";
	str *stringPTR = &original;
	str& stringREF = original;

	std::cout << &original << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << original << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}