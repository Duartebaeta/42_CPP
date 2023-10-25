#include "../incl/Span.hpp"

Span::Span() : N(0)
{
	std::cout << "[Span] default constructor has been called" << std::endl;
}

Span::Span(const Span& copy)
{
	*this = copy;
	std::cout << "[Span] copy constructor has been called" << std::endl;
}

Span&	Span::operator=(const Span& copy)
{
	this->N = copy.N;
	std::cout << "[Span] copy assignment operator has been called" << std::endl;
	return (*this);
}

Span::~Span()
{
	std::cout << "[Span] default destructor has been called" << std::endl;
}

Span::Span(unsigned int N) : N(N)
{
	std::cout << "[Span] Parameter constructor has been called" << std::endl;
}

void	Span::addNumber(int num)
{
	if (data.size() >= N)
		throw std::runtime_error("Span is full");
	data.push_back(num);
}

unsigned int	Span::longestSpan()
{
	std::vector<int>::iterator min = std::min_element(data.begin(), data.end());
	std::vector<int>::iterator max = std::max_element(data.begin(), data.end());

	return (*max - *min);
}

unsigned int	Span::shortestSpan()
{
	if (data.size() < 2) {
		throw std::runtime_error("Vector must contain at least two elements to find a span");
	}

	std::sort(data.begin(), data.end());

	unsigned int smallestSpan = std::numeric_limits<unsigned int>::max();

	for (std::vector<unsigned int>::size_type i = 1; i < data.size(); ++i) {
		unsigned int span = data[i] - data[i - 1];
		if (span < smallestSpan)
			smallestSpan = span;
	}

	return smallestSpan;
}