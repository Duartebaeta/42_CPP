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

bool	BitcoinExchange::validate_date(str date)
{
	struct tm 		tm;
	if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
		return (false);
	return (true);
}

bool	BitcoinExchange::validate_float(str value)
{
	std::istringstream ss (value);

	float f;
	ss >> f;
	if (f > 1000 || f < 0)
		return (false);
	return !ss.fail() && ss.eof();
}

bool		BitcoinExchange::validateData(str line)
{
	size_t	pipePos = line.find('|');
	if (pipePos == std::string::npos || pipePos == 0 || pipePos == line.length() - 1)
	{
		std::cout << "Error: Invalid input => " << line << std::endl;
		return (false);
	}

	str date = line.substr(0, pipePos);
	str value = line.substr(pipePos + 1);

	date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
	if (date.length() != 10 || !validate_date(date))
	{
		std::cout << "Error: Invalid input => " << line << std::endl;
		return (false);
	}
	if (!validate_float(value))
	{
		std::cout << "Error: Invalid number => " << line << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::exchange()
{
	try {
		this->parseData();
	} catch(std::exception &e) {
		throw;
	}

	if (this->filename.size() <= 4 || this->filename.substr(filename.size() - 4, 4).compare(".csv"))
		throw std::runtime_error("Input file must be in the .csv format");
	std::ifstream file(this->filename.c_str());
	str line;
	int	counter = -1;


	if (!file.is_open())
		throw std::runtime_error("File doesn't exist");
	
	while (getline(file, line))
	{
		if (counter++ == -1)
			continue;
		if (this->validateData(line))
			this->linkData(line);
	}
	
	file.close();
}