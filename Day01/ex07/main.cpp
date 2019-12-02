#include <iostream>
#include <fstream>
#include <string>
#include "Replace.hpp"
int main(int argc, char **argv)
{
	std::string tmp = "";
	std::string output = "";
	std::ifstream file_istream;
	std::ofstream file_ostream;

	if (argc == 4)
	{
		Replace a(argv[2], argv[3]);
		std::string b(argv[1]);
		b += ".replace";
		file_istream.open(argv[1]);
		if (file_istream.is_open())
		{
			for (; std::getline(file_istream, tmp) ;)
			{
				a.setCur(tmp);
				if (tmp.find(argv[2]) != std::string::npos)
					a.replace();
				output += a.cur_;
				output += "\n";
			}
			file_istream.close();
			file_ostream.open(b);
			file_ostream << output;
			file_ostream.close();
		}
	}
	else
		std::cout << "Usage:[./replace [file_name] [replace_str] [source_str]" << std::endl;
	return 0;
}