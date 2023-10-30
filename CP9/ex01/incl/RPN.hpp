#pragma once

#include <iostream>
#include <stack>

typedef std::string str;

class RPN
{
	private:
		std::stack<int>	stack;

		int	operations(char op);
	public:
		RPN();
		RPN(const RPN& copy);
		RPN&	operator=(const RPN& copy);
		~RPN();

		void	solve(str equation);
};