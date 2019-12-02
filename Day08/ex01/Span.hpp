//
// Created by Gennady GAVRYLYSHYN on 2019-10-12.
//

#ifndef PISCINE_SPAN_HPP
#define PISCINE_SPAN_HPP

#include <iostream>
#include <vector>

class Span {
public:
	Span();
	Span(unsigned int size);
	Span(Span const &);
	Span &operator=(Span const &);
	~Span();
	void	addNumber(int);
	int		shortestSpan();
	int		longestSpan();
	class AlreadyStored : public std::exception
	{
	public:
		AlreadyStored();
		AlreadyStored(AlreadyStored const &);
		AlreadyStored & operator=(AlreadyStored const &);
		const char* what() const _NOEXCEPT;
		~AlreadyStored() _NOEXCEPT;
	};
	class RangeLimit : public std::exception
	{
	public:
		RangeLimit();
		RangeLimit(RangeLimit const &);
		RangeLimit & operator=(RangeLimit const &);
		const char* what() const _NOEXCEPT;
		~RangeLimit() _NOEXCEPT;
	};
	class NotEnoughSize : public std::exception
	{
	public:
		NotEnoughSize();
		NotEnoughSize(NotEnoughSize const &);
		NotEnoughSize & operator=(NotEnoughSize const &);
		const char* what() const _NOEXCEPT;
		~NotEnoughSize() _NOEXCEPT;
	};
private:
	unsigned int			_size;
	std::vector<int>		_array;
};


#endif //PISCINE_SPAN_HPP
