//
// Created by Gennady GAVRYLYSHYN on 2019-10-12.
//
#ifndef PISCINE_MUTANTSTACK_HPP
#define PISCINE_MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack() {}
	MutantStack(MutantStack const &a) { *this = a; }
	MutantStack& operator=(MutantStack const &a)
	{
		*this = a;
		return *this;
	}
	~MutantStack() {}
	iterator begin() { return std::begin(std::stack<T>::c); }
	iterator end() { return std::end(std::stack<T>::c); }

};


#endif //PISCINE_MUTANTSTACK_HPP
