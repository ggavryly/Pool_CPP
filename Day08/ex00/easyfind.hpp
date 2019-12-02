#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP
#include <iostream>

template <typename T>
int easyfind(T &cont, int needle)
{
	typename T::iterator res = std::find(cont.begin(), cont.end(), needle);
	if (res == cont.end())
		throw std::exception();
	return *res;
}

#endif