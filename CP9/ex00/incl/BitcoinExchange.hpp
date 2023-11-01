#pragma once

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>

typedef std::string str;

class BitcoinExchange
{
	private:
		str filename;
		std::map<std::string, float> data;

		void	parseData();
		void	linkData(str line);
		int		validateData(str line);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange(str argv);

		void	exchange();
};