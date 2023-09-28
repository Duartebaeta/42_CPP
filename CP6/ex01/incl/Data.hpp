#pragma once

#include <iostream>

class Data
{
	public:
		int	a;
		double b;
		char c;
		Data();
		Data(int a, double b, char c);
		Data(const Data& copy);
		~Data();
		Data &operator=(const Data& copy);
};