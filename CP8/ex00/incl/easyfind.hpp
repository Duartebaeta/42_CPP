#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // for std::find
#include <stdexcept> // for std::runtime_error

template <typename T>
typename T::iterator	easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end()) {
		throw std::runtime_error("Element not found.");
	}
	return it;
}