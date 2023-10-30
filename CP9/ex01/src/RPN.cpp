#include "../incl/RPN.hpp"

RPN::RPN()
{
	std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const RPN& copy)
{
	*this = copy;
	std::cout << "Default constructor called" << std::endl;
}

RPN&	RPN::operator=(const RPN& copy)
{
	this->stack = copy.stack;
	std::cout << "Copy assignemnt operator called" << std::endl;
	return (*this);
}

RPN::~RPN()
{
	std::cout << "Default destructor called" << std::endl;
}

int	RPN::operations(char op)
{
	if (stack.empty())
		throw std::runtime_error("Error: Not enough numbers to do operation");
	int last = stack.top();
	stack.pop();
	if (stack.empty())
		throw std::runtime_error("Error: Not enough numbers to do operation");
	int first = stack.top();
	stack.pop();

	switch (op)
	{
		case '+':
			return (first + last);
			break;
		case '-':
			return (first - last);
			break;
		case '*':
			return (first * last);
			break;
		case '/':
			return (first / last);
			break;
		default:
			return (0);
			break;
	}
}

void	RPN::solve(str equation)
{
	str operators = "+-*/";

	for (int counter = 0; equation[counter]; counter++)
	{
		if (equation[counter] == ' ')
			continue;
		else if (equation[counter] >= '0' && equation[counter] <= '9')
			stack.push(equation[counter] - '0');
		else if (operators.find(equation[counter]) != str::npos)
			stack.push(operations(equation[counter]));
		else
		{
			std::cout << "Error: Invalid char" << std::endl;
			return;
		}
	}
	if (stack.size() != 1)
		std::cout << "Error: Not enough operations for final result" << std::endl;
	else
		std::cout << stack.top() << std::endl;
}