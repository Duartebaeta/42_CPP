#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>
#include <sstream>
#include <cctype>
#include <map>

typedef std::string str;

class BitcoinExchange
{
	private:
		str filename;
		std::map<std::string, float> data;

		void	parseData();
		void	linkData(str line);
		bool	validateData(str line);
		bool	validate_date(str date);
		bool	validate_float(str value);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange(str argv);

		void	exchange();
};