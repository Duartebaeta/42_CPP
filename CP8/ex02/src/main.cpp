#include "../incl/MutantStack.hpp"

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

int main() {
	MutantStack<int> mstack;

	std::cout << "Pushing elements onto MutantStack..." << std::endl;

	// Push elements onto the stack
	for (int i = 0; i < 5; ++i) {
		mstack.push(i);
	}

	// Displaying the stack using iterators
	std::cout << "Stack elements: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Testing the pop operation
	std::cout << "Popping an element..." << std::endl;
	mstack.pop();

	// Display the stack again to confirm pop operation
	std::cout << "Stack elements after pop: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Initializing another std::stack from MutantStack
	std::stack<int> s(mstack);

	// Displaying elements of the std::stack
	std::cout << "Elements in std::stack: ";
	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}
	std::cout << std::endl;

	return 0;
}
