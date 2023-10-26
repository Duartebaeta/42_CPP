#pragma once

#include <iostream>
#include <list>
#include <stack>
#include <cstdlib>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
		{
			std::cout << "[MutantStack] default constructor called" << std::endl;
		}
		MutantStack(const MutantStack& copy)
		{
			*this = copy;
			std::cout << "[MutantStack] copy constructor called" << std::endl;
		};
		MutantStack& operator=(const MutantStack& copy)
		{
			*this = *copy;
			std::cout << "[MutantStack] copy assignment operator called" << std::endl;
			return (*this);
		};
		~MutantStack()
		{
			std::cout << "[MutantStack] default destructor called" << std::endl;
		}
		//Iterators
		typedef typename std::stack<T>::container_type container;
		typedef typename container::iterator iterator;

		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
};