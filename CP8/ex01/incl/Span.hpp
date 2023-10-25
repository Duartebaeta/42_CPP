#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <algorithm> // for std::find
#include <stdexcept> // for std::runtime_error

class Span
{
	private:
		unsigned int N;
		std::vector<int> data;

	public:
		Span();
		Span(const Span& copy);
		Span &operator=(const Span& copy);
		~Span();
		Span(unsigned int N);

		void addNumber(int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void	addRange(unsigned int begin, unsigned int end);
};