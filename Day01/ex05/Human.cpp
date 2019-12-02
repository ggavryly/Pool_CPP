#include "Human.hpp"
#include <iostream>
#include <sstream>

Brain & Human::getBrain()
{
	return this->brain_;
}

std::string Human::identify()
{
	std::stringstream a;
	a << &this->brain_;
	return a.str();
}
