#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

typedef std::string str;

class BitcoinExchange
{
	private:
		str filename;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange(str argv);

		void	exchange();
}