#include "Brain.hpp"
#include <sstream>

std::string Brain::identify()
{
	std::stringstream a;
	a << this;
	return a.str();
}