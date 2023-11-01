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
	this->filename = copy.filename;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(str filename) :  filename(filename)
{
	std::cout << "Parameter constructor called" << std::endl;
}

void	BitcoinExchange::parseData()
{
	std::ifstream file("data.csv");
	str line;
	int	counter = -1;


	if (!file.is_open())
		throw std::runtime_error("Database is invalid");
	
	while (getline(file, line))
	{
		if (counter++ == -1)
			continue;
		data.insert(std::make_pair(line.substr(0, 10), strtof((line.substr((line.find(',')) + 1)).c_str(), NULL)));
	}
	
	file.close();
}

void	BitcoinExchange::linkData(str line)
{
	std::map<std::string, float>::iterator it = data.find(line.substr(0, 10));
	if(it != data.end()) {
		std::cout << it->first << " => " << it->second << " = " << (it->second * strtof((line.substr(line.find('|') + 1)).c_str(), NULL)) << std::endl;
	}
	else
	{
		std::map<std::string, float>::iterator it = data.lower_bound(line.substr(0, 10));
		if(it != data.begin()) {
			--it;
			std::cout << it->first << " => " << it->second << " = " << (it->second * strtof((line.substr(line.find('|') + 1)).c_str(), NULL)) << std::endl;
		} else {
			std::cout << "Error: No date lower was available" << std::endl;
		}
	}
}

int		BitcoinExchange::validateData(str line)
{
	struct tm 		tm;
	if (strptime(line.substr(0, 10).c_str(), "%Y-%m-%d", &tm) == NULL)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (0);
	}
	try {
		if (strtof((line.substr(line.find('|') + 1)).c_str(), NULL) < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			return (0);
		}
		else if (strtof((line.substr(line.find('|') + 1)).c_str(), NULL) > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			return (0);
		}
	} catch (std::exception &e) {
		std::cout << "Error: too large a number." << std::endl;
		return (0);
	}
	return (1);
}

void	BitcoinExchange::exchange()
{
	try {
		this->parseData();
	} catch(std::exception &e) {
		throw;
	}

	std::ifstream file(this->filename.c_str());
	str line;
	int	counter = -1;


	if (!file.is_open())
		throw std::runtime_error("Filename is invalid");
	
	while (getline(file, line))
	{
		if (counter++ == -1)
			continue;
		if (this->validateData(line))
			this->linkData(line);
	}
	
	file.close();
}