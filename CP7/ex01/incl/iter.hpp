#pragma once

#include <iostream>

void printDouble(double x, int i) {
    std::cout << x << ' ';
	(void) i;
}

template <typename T> void test(T array, int counter)
{
	std::cout << "function result: " << counter << ": " << array << std::endl;
}

template <typename T>
void	iter(T *array, T lenght, void (*test)(T array, int counter))
{
	for (int counter = 0; counter < lenght; counter++)
		test(array[counter], counter);
}