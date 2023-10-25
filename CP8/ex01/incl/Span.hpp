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
		
		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end)
		{
			unsigned int fill = std::distance(begin, end);
			if (data.size() + fill > N)
				throw std::runtime_error("Too many elements to add");
			data.insert(data.end(), begin, end);
		}
};