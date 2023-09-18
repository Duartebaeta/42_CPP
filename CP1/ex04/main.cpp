#include "./File.hpp"

str	line_returner(str line, str s1, str s2)
{
	if (s1.length() == 0)
		return line;
	str new_line;
	unsigned long	pos;
	while ((pos = line.find(s1)) != std::string::npos)
	{
		new_line.append(line.substr(0, pos));
		line = line.substr(pos + s1.length());
		new_line.append(s2);
	}
	new_line.append(line);
	return (new_line);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Not enough arguments were provided" << std::endl;
		return 1;
	}

	input_handler	file;
	output_handler	outfile;
	str outfilename = argv[1];
	outfilename.append(".replace");

	file.open(argv[1]);
	if (file.is_open()) {
		str line;
		outfile.open(outfilename.c_str());
		while (getline(file, line))
		{
			if (outfile.is_open())
			{
				outfile << line_returner(line, argv[2], argv[3]) << std::endl;
			}
			else
			{
				std::cout << "Unable to write to file" << std::endl;
				return 2;
			}
		}
		file.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
	}
	return 0;
}
