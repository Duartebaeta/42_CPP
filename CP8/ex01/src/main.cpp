#include "../incl/Span.hpp"

int	main()
{
	Span sp = Span(500);
	srand(time(NULL));
	try {
		sp.addRange(0, 10);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}