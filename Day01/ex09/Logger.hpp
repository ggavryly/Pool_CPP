#ifndef LOGGER_HPP
# define LOGGER_HPP
#include <iostream>
#include <fstream>
class Logger
{
public:
	Logger(std::string const & filen_path);
	void log(std::string const & dest, std::string const & message);
private:
	void logToConsole(std::string const &);
	void logToFile(std::string const &);
	std::string makeLogEntry(std::string const &);
	std::string file_name;
};

#endif