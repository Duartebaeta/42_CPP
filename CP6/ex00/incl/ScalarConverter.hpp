#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <math.h>

typedef std::string str;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& copy);
	public:
		static void	convert(str value);
		static void	float_convert(float value, str v);
		static void	double_convert(double value, str v);
		static void	int_convert(int value);
		static void	char_convert(char value);
		static void	special_convert(str value);
		static std::string formatFloat(float value);
		static std::string formatDouble(double value);
		static void get_char(int c);
		static void get_int(float c, str value);
		static void get_float(double c, str value);
};