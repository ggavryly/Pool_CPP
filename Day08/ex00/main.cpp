#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	v.push_back(-2);
	v.push_back(-5);
	v.push_back(2552);
	v.push_back(112);
	v.push_back(1);
	try {
		std::cout << easyfind(v, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Not exist value" << std::endl;
	}
	return 0;
}
