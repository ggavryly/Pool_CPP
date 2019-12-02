#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

struct Pony
{
	Pony();
	~Pony();
	void scream();
private:
	int		legs_count;
	bool	unicorn;
};

#endif