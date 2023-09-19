#include "../incl/Bureaucrat.hpp"

int main() {
	std::cout << "\n--- Default Construction Test ---\n";
	try {
		Bureaucrat a;
		std::cout << a;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Grade Parameter Test ---\n";
	try {
		Bureaucrat b(42, "Jack");
		std::cout << b;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Grade Too High Test ---\n";
	try {
		Bureaucrat c(0, "Daniel");
		std::cout << c;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Grade Too Low Test ---\n";
	try {
		Bureaucrat d(151, "Bob");
		std::cout << d;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Copy Construction Test ---\n";
	try {
		Bureaucrat e(100, "Zach");
		Bureaucrat f(e);
		std::cout << f;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Assignment Operation Test ---\n";
	try {
		Bureaucrat g(110, "Mark");
		Bureaucrat h(120, "Marc with a C");
		h = g;
		std::cout << h;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Increment Grade Test ---\n";
	try {
		Bureaucrat i(2, "Bored");
		std::cout << "Before: " << i;
		i.incrementGrade();
		std::cout << "After: " << i;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	std::cout << "\n--- Decrement Grade Test ---\n";
	try {
		Bureaucrat j(149, "Insert Name");
		std::cout << "Before: " << j;
		j.decrementGrade();
		std::cout << "After: " << j;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
	}

	return 0;
}
