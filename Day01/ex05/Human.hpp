#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"
#include <iostream>

class Human
{
public:
	Brain &getBrain();
	std::string identify();
	Brain brain_;
};

# endif