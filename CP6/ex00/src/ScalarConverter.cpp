#include "../incl/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

// ScalarConverter::ScalarConverter(str arg)
// {
// 	std::cout << "Parameter constructor called" << std::endl;
// 	this->convert(arg);
// }

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

void	ScalarConverter::convert(str value)
{
	bool found = false;
	str array[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (int counter = 0; counter < 6; counter++)
	{
		if (array[counter] == value)
		{
			found = true;
			break;
		}
	}
	if (found)
		ScalarConverter::special_convert(value);
	else if (value.length() == 1 && (value[0] < 48 || value[0] > 57))
		ScalarConverter::char_convert(value[0]);
	else if (value.find('.') != str::npos)
	{
		if (value.find('f') != str::npos)
		{
			float myFloat;
			value.resize(value.size() - 1);
			std::istringstream iss(value);

			if (!(iss >> myFloat))
				std::cout << "Bad argument" << std::endl;
			else
				ScalarConverter::float_convert(myFloat, value);
		}
		else
		{
			double myDouble;
			std::istringstream iss(value);

			if (!(iss >> myDouble))
				std::cout << "Bad argument" << std::endl;
			else
				ScalarConverter::double_convert(myDouble, value);
		}
	}
	else
	{
		int myInt;
		std::istringstream iss(value);

		if (!(iss >> myInt))
			std::cout << "Bad argument" << std::endl;
		else
			ScalarConverter::int_convert(myInt);
	}
}

std::string ScalarConverter::formatFloat(float value) {
	std::ostringstream out;
	out << value;
	std::string str = out.str();

	if (str.find('.') == std::string::npos) {
		str += ".0f";
	}
	else
		str += "f";

	return str;
}

std::string ScalarConverter::formatDouble(double value) {
	std::ostringstream out;
	out << value;
	std::string str = out.str();

	if (str.find('.') == std::string::npos) {
		str += ".0";
	}

	return str;
}

void	ScalarConverter::special_convert(str c)
{
	std::cout << "Enter char: " << c << std::endl;
}

void	ScalarConverter::char_logic(str value)
{
	str myChar;
	int c;
	try {
		c = int_logic(value);
	}
	catch (std::exception &e) {
		std::cout << "char: Not Possible" << std::endl;
	}
	if (c <= 31 || c >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}

int	ScalarConverter::int_logic(str value)
{
	try {
		float_logic(value);
	}
	catch (std::exception &e) {
		std::cout << "int: Not possible";
	}
	int	myInt;
	std::istringstream so(value);
	if (!(so >> myInt))
	{
		std::cout << "int: Not possible" << std::endl;
		throw std::exception();
	}
	else
	{
		std::cout << "int: " << myInt << std::endl;
		return (myInt);
	}
}

void ScalarConverter::float_logic(str value)
{
	float	myFloat;
	std::istringstream so(value);
	if (!(so >> myFloat))
	{
		std::cout << "float: Not possible" << std::endl;
		throw std::exception();
	}
	else
		std::cout << "float: " << myFloat << std::endl;
}

void ScalarConverter::double_logic(str value)
{
	double myDouble;
	std::istringstream iss(value);

	if (!(iss >> myDouble))
	{
		std::cout << "double: Not possible" << std::endl;
		throw std::exception();
	}
	else
		std::cout << "double: " << myDouble << std::endl;
}

void	ScalarConverter::char_convert(char c)
{
	if (c < 31 || c == 127)
	{
		std::cout << "Invalid argument, non printable char"<< std::endl;
		return ;
	}

	int		myInt = static_cast<int>(c);
	float	myFloat = static_cast<float>(c);
	double	myDouble = static_cast<double>(c);

	std::cout << "char: " << c << std::endl << "int: " << myInt << std::endl << "float: " << formatFloat(myFloat) << std::endl << "double: " << formatDouble(myDouble) << std::endl;
}

void	ScalarConverter::int_convert(int c)
{
	float myFloat = static_cast<float>(c);
	double myDouble = static_cast<double>(c);
	if (c <= 31 || c >= 127)
	{
		str myChar = "Non displayable";
		std::cout << "char: " << myChar << std::endl << "int: " << c << std::endl << "float: " << formatFloat(myFloat) << std::endl << "double: " << formatDouble(myDouble) << std::endl;
	}
	else
	{
		char myChar = static_cast<char>(c);
		std::cout << "char: " << myChar << std::endl << "int: " << c << std::endl << "float: " << formatFloat(myFloat) << std::endl << "double: " << formatDouble(myDouble) << std::endl;
	}
}

void	ScalarConverter::float_convert(float c, str value)
{
	str badChar = "";
	str badInt = "";
	char goodChar;
	int	myInt;
	std::stringstream ss;
	std::istringstream so(value);
	double myDouble = static_cast<double>(c);
	if (!(so >> myInt))
	{
		badInt = "Not possible";
		badChar = "Not possible";
	}
	else
	{
		ss << myInt;
		if (myInt < 0 || myInt > 127)
			badChar = "Not possible";
		else
		{
			if (myInt <= 31)
				badChar = "Not printable";
			else
				goodChar = myInt;
		}
	}
	std::cout << "char: " << (badChar.length() == 0 ? std::string(1, goodChar) : badChar) << std::endl << "int: " << (badInt.length() == 0 ? ss.str() : badInt) << std::endl << "float: " << formatFloat(c) << std::endl << "double: " << formatDouble(myDouble) << std::endl;
}

void	ScalarConverter::double_convert(double c, str value)
{
	(void)c;
	std::stringstream ss;
	std::istringstream so(value);
}
