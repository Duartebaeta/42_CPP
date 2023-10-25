#include "../incl/Span.hpp"

int	main()
{
	Span sp = Span(500);
	sp.addRange(sp.begin(), sp.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
	return 0;
}