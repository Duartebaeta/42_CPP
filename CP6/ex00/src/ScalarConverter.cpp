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
		for (int counter = 0; value[counter]; counter++)
		{
			if (value[counter] < 48 || value[counter] > 57)
			{
				std::cout << "Bad argument" << std::endl;
				return ;
			}
		}
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
	if (c == "-inff" || c == "-inf")
		std::cout << "char: Not possible" << std::endl << "int: Not possible" << std::endl << "float: -inff" << std::endl << "double: -inf" << std::endl;
	else if (c == "+inff" || c == "+inf")
		std::cout << "char: Not possible" << std::endl << "int: Not possible" << std::endl << "float: +inff" << std::endl << "double: +inf" << std::endl;
	else if (c == "nanf" || c == "nan")
		std::cout << "char: Not possible" << std::endl << "int: Not possible" << std::endl << "float: nanf" << std::endl << "double: nan" << std::endl;
}

void	ScalarConverter::char_convert(char c)
{
	if (c <= 31 || c == 127)
	{
		std::cout << "Invalid argument, non printable char"<< std::endl;
		return ;
	}

	int		myInt = static_cast<int>(c);
	float	myFloat = static_cast<float>(c);
	double	myDouble = static_cast<double>(c);

	std::cout << "char: " << c << std::endl << "int: " << myInt << std::endl << "float: " << formatFloat(myFloat) << std::endl << "double: " << formatDouble(myDouble) << std::endl;
}

void	ScalarConverter::get_char(int c)
{
	std::stringstream ss;

	if (c < 0 || c > 127)
		ss << "Not possible";
	else
	{
		if (c <= 31)
			ss << "Not printable";
		else
			ss << static_cast<char>(c);
	}
	std::cout << "char: " << ss.str() << std::endl;
}

void	ScalarConverter::get_int(float c, str value)
{
	std::stringstream ss;
	std::istringstream so(value);
	int	myInt;

	if (!(so >> myInt))
	{
		ss << "Not possible";
		ScalarConverter::get_char(-1);
	}
	else
	{
		myInt = static_cast<int>(c);
		ss << myInt;
		ScalarConverter::get_char(myInt);
	}
	std::cout << "int: " << ss.str() << std::endl;
}

void	ScalarConverter::get_float(double c, str value)
{
	std::stringstream ss;
	std::istringstream so(value);
	float	myFloat;

	if (!(so >> myFloat))
	{
		ss << "Not possible";
		ScalarConverter::get_int(-1, value);
	}
	else
	{
		myFloat = static_cast<float>(c);
		ss << formatFloat(myFloat);
		ScalarConverter::get_int(myFloat, value);
	}
	std::cout << "float: " << ss.str() << std::endl;
}

void	ScalarConverter::int_convert(int c)
{
	float myFloat = static_cast<float>(c);
	double myDouble = static_cast<double>(c);
	ScalarConverter::get_char(c);
	std::cout << "int: " << c << std::endl << "float: " << formatFloat(myFloat) << std::endl << "double: " << formatDouble(myDouble) << std::endl;
}

void	ScalarConverter::float_convert(float c, str value)
{
	double myDouble = static_cast<double>(c);
	ScalarConverter::get_int(c, value);
	std::cout << "float: " << formatFloat(c) << std::endl << "double: " << formatDouble(myDouble) << std::endl;
}

void	ScalarConverter::double_convert(double c, str value)
{
	ScalarConverter::get_float(c, value);
	std::cout << "double: " << formatDouble(c) << std::endl;
}
