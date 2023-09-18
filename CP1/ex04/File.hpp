#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <string>
#include <fstream>

typedef std::string str;
typedef std::ifstream input_handler;
typedef std::ofstream output_handler;

str	line_returner(str line, str s1, str s2);

#endif