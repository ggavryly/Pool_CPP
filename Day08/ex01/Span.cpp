//
// Created by Gennady GAVRYLYSHYN on 2019-10-12.
//

#include "Span.hpp"

Span::AlreadyStored::AlreadyStored() {}
Span::AlreadyStored::AlreadyStored(const Span::AlreadyStored &) {}
Span::AlreadyStored& Span::AlreadyStored::operator=(const Span::AlreadyStored &) {return *this;}
Span::AlreadyStored::~AlreadyStored() throw() {}
const char* Span::AlreadyStored::what() const throw() { return "This value already stored in span"; }

Span::RangeLimit::RangeLimit() {}
Span::RangeLimit::RangeLimit(const Span::RangeLimit &) {}
Span::RangeLimit& Span::RangeLimit::operator=(const Span::RangeLimit &) {return *this;}
Span::RangeLimit::~RangeLimit() throw() {}
const char* Span::RangeLimit::what() const throw() { return "Array is full"; }

Span::NotEnoughSize::NotEnoughSize() {}
Span::NotEnoughSize::NotEnoughSize(const Span::NotEnoughSize &) {}
Span::NotEnoughSize& Span::NotEnoughSize::operator=(const Span::NotEnoughSize &) {return *this;}
Span::NotEnoughSize::~NotEnoughSize() throw() {}
const char* Span::NotEnoughSize::what() const throw() { return "Not enough size to find short/long spans min-size{2}"; }

Span::Span() : _size(0)
{}

Span::Span(unsigned int size) : _size(size)
{}

Span::Span(Span const &a) {
	*this = a;
}
Span::~Span() {}

Span& Span::operator=(Span const &a) {
	this->_array = a._array;
	this->_size = a._size;
	return *this;
}

void Span::addNumber(int a) {
	if (this->_size != this->_array.size())
	{
		if (std::find(this->_array.begin(), this->_array.end(), a) == this->_array.end())
			this->_array.push_back(a);
		else
			throw AlreadyStored();
	}
	else
		throw RangeLimit();
}

int Span::shortestSpan() {
	int min_delta = INT_MAX;
	int delta;
	if (this->_array.size() > 1) {
		std::vector<int> cpy = this->_array;
		std::sort(cpy.begin(), cpy.end());
		std::vector<int>::iterator prev = cpy.begin();
		for (std::vector<int>::iterator it = cpy.begin() + 1; it != cpy.end(); it++) {
			delta = std::abs(static_cast<int>(*it) - static_cast<int>(*prev));
			if (delta < min_delta)
				min_delta = delta;
			prev = it;
		}
		return min_delta;
	}
	else
		throw NotEnoughSize();
}

int Span::longestSpan() {
	if (this->_array.size() > 1) {
		std::vector<int>::iterator min = std::max_element(this->_array.begin(), this->_array.end());
		std::vector<int>::iterator max = std::min_element(this->_array.begin(), this->_array.end());
		return (abs(*max - *min));
	} else
		throw NotEnoughSize();
}