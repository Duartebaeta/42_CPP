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
		//ScalarConverter(str arg);
		static void	convert(str value);
		static void	float_convert(float value, str v);
		static void	double_convert(double value, str v);
		static void	int_convert(int value);
		static void	char_convert(char value);
		static void	special_convert(str value);
		static std::string formatFloat(float value);
		static std::string formatDouble(double value);
		static void	char_logic(str value);
		static int	int_logic(str v);
		static void	float_logic(str v);
		static void	double_logic(str v);
};