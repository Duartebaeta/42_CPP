#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <sstream>
#include <ctime>

typedef std::string str;

class PmergeMe
{
	private:
		std::vector<int>					v_unsorted;
		std::vector<int>					v_sorted;
		std::vector<std::pair<int, int> >	v;

		std::list<int>					l_unsorted;
		std::list<int>					l_sorted;
		std::list<std::pair<int, int> >	l;

		int	odd;

		void	sort_vector();
		void	v_make_pairs();
		
		void	sort_list();
		void	l_make_pairs();

		int		my_atoi(str s);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe&	operator=(const PmergeMe& copy);
		~PmergeMe();

		void	sort(char **argv);
};