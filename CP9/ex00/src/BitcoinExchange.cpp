#include "../incl/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : filename("")
{
	std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	*this.filename = copy.filename;
	std::cout << "Copy assignment operator called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(str filename) :  filename(filename)
{
	std::cout << "Parameter constructor called" << std::endl;
}

void	BitcoinExchange::exchange()
{
	std::ifsteam file(this.filename);
	str line;
	std::vector<std::string> fileContent;

	if (!file.is_open())
		throw std::runtime_error("Filename is invalid");
	
	while (getline())
}