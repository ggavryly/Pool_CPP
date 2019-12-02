#include "Logger.hpp"

int main(void)
{
	Logger a("test.txt");
	a.log("logToFile", "kaka");
	a.log("logToConsole", "kaka");
}