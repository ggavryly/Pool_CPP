#include "Logger.hpp"

Logger::Logger(std::string const &file_path)
{
	this->file_name = file_path;
}

void Logger::logToConsole(std::string const & message)
{
	std::cout << Logger::makeLogEntry(message) << std::endl;
}

void Logger::logToFile(std::string const & message)
{
	time_t a = time(&a);
	std::ofstream file_output;
	file_output.open(this->file_name, std::ios_base::app);
	if (file_output.is_open())
		file_output << Logger::makeLogEntry(message);
	else
	{
		file_output.open(this->file_name, std::ios_base::app | std::ios_base::trunc);
		file_output << Logger::makeLogEntry(message) << std::endl;
	}
	file_output.close();
}

std::string Logger::makeLogEntry(std::string const &message)
{
	time_t a = time(&a);
	time_t time_tmp = std::time(&time_tmp);
	std::string out = "";
	out += "\n===LOG_START===\n[";
	out += std::to_string(a);
	out += "] ";
	out += message;
	out += "\n===LOG_END===\n";
	return out;
}

void Logger::log(std::string const &dest, std::string const &message)
{
	void (Logger::*action[])(std::string const & message) = {&Logger::logToConsole, &Logger::logToFile};
	std::string action_names[] = {"logToConsole", "logToFile"};
	for (size_t i = 0; i < 2; i++)
	{
		if (action_names[i] == dest)
			(this->*action[i])(message);
	}
}