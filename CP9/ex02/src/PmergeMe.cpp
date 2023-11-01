#include "../incl/PmergeMe.hpp"

PmergeMe::PmergeMe() : odd(-1)
{
	std::cout << "Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& copy)
{
	this->l = copy.l;
	this->l_unsorted = copy.l_unsorted;
	this->l_sorted = copy.l_sorted;
	this->v = copy.v;
	this->v_unsorted = copy.v_unsorted;
	this->v_sorted = copy.v_sorted;
	this->odd = copy.odd;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "Default destructor called" << std::endl;
}

int	PmergeMe::my_atoi(str s)
{
	std::istringstream iss(s);
	int num;
	iss >> num;
	if (iss.fail())
		throw std::runtime_error("Invalid number");
	return num;
}

void	PmergeMe::v_make_pairs()
{
	if (v_unsorted.size() % 2)
	{
		odd = v_unsorted.back();
		v_unsorted.pop_back();
	}

	std::vector<int>::iterator minIt = std::min_element(v_unsorted.begin(), v_unsorted.end());
	v_sorted.push_back(*minIt);
	v_unsorted.erase(minIt);
	std::vector<int>::iterator maxIt = std::max_element(v_unsorted.begin(), v_unsorted.end());
	v_sorted.push_back(*maxIt);
	v_unsorted.erase(maxIt);



	for (std::vector<int>::iterator it = v_unsorted.begin(); it != v_unsorted.end(); it += 2) {
		if ((it + 1) == v_unsorted.end())
			break;
		if (*it < *(it + 1)) {
			v.push_back(std::make_pair(*it, *(it + 1)));
		} else {
			v.push_back(std::make_pair(*(it + 1), *it));
		}
	}
}

void	PmergeMe::sort_vector()
{
	v_make_pairs();
	v_sorted.reserve(3001);
	std::vector<int>::iterator small_it;

	for (std::vector<std::pair<int, int> >::iterator it = v.begin(); it != v.end(); ++it)
	{
		small_it = v_sorted.begin();
		while (*small_it < it->first && small_it != v_sorted.end())
			small_it++;
		v_sorted.insert(small_it, it->first);
		while (*small_it < it->second && small_it != v_sorted.end())
			small_it++;
		v_sorted.insert(small_it, it->second);
	}
	if (odd != -1)
	{
		std::vector<int>::iterator it = v_sorted.begin();
		while (it != v_sorted.end() && *it < odd)
			it++;
		v_sorted.insert(it, odd);
	}
}

void	PmergeMe::l_make_pairs()
{
	if (l_unsorted.size() % 2)
	{
		odd = l_unsorted.back();  // Get the last element
		l_unsorted.pop_back();    // Remove the last element
	}

	std::list<int>::iterator minIt = std::min_element(l_unsorted.begin(), l_unsorted.end());
	l_sorted.push_back(*minIt);
	l_unsorted.erase(minIt);
	std::list<int>::iterator maxIt = std::max_element(l_unsorted.begin(), l_unsorted.end());
	l_sorted.push_back(*maxIt);
	l_unsorted.erase(maxIt);


	std::list<int>::iterator nextIt;
	for (std::list<int>::iterator it = l_unsorted.begin(); it != l_unsorted.end(); it++) {
		nextIt = it;
		++nextIt;
		if (*it < *nextIt) {
			l.push_back(std::make_pair(*it, *nextIt));
		} else {
			l.push_back(std::make_pair(*nextIt, *it));
		}
	}
}

void	PmergeMe::sort_list()
{
	l_make_pairs();
	std::list<int>::iterator small_it;

	for (std::list<std::pair<int, int> >::iterator it = l.begin(); it != l.end(); ++it)
	{
		small_it = l_sorted.begin();
		while (*small_it < it->first && small_it != l_sorted.end())
			small_it++;
		l_sorted.insert(small_it, it->first);
		while (*small_it < it->second && small_it != l_sorted.end())
			small_it++;
		l_sorted.insert(small_it, it->second);
	}
	if (odd != -1)
	{
		std::list<int>::iterator it = l_sorted.begin();
		while (it != l_sorted.end() && *it < odd)
			it++;
		l_sorted.insert(it, odd);
	}
}

void	PmergeMe::sort(str argument)
{
	str	temp;

	for (int counter = 0; argument[counter]; counter++)
	{
		if ((argument[counter] < '0' || argument[counter] > '9') && argument[counter] != ' ')
			throw std::runtime_error("Error: invalid input");
		else if (argument[counter] == ' ')
		{
			try {
				v_unsorted.push_back(my_atoi(temp));
				l_unsorted.push_back(my_atoi(temp));
				temp.clear();
			} catch (std::exception &e) {
				throw;
			}
		}
		temp.push_back(argument[counter]);
	}
	try {
		v_unsorted.push_back(my_atoi(temp));
		l_unsorted.push_back(my_atoi(temp));
		temp.clear();
	} catch (std::exception &e) {
		throw;
	}
	std::cout << "Before: " << argument << std::endl;
	clock_t	_vectorTime = clock();
	sort_vector();
	_vectorTime = clock() - _vectorTime;
	std::cout << "After: ";
	for (std::vector<int>::iterator it = v_sorted.begin(); it != v_sorted.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << v_sorted.size() << " elements with std::vector : " << (double)( (double)_vectorTime / CLOCKS_PER_SEC ) * 1000 << " miliseconds " << std::endl;
	clock_t	_listTime = clock();
	sort_list();
	_listTime = clock() - _listTime;
	std::cout << "Time to process a range of " << v_sorted.size() << " elements with std::list : " << (double)( (double)_listTime / CLOCKS_PER_SEC ) * 1000 << " miliseconds " << std::endl;
}