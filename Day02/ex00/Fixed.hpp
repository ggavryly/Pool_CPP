#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &);
	~Fixed();
	Fixed &operator=(Fixed const &);
	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int value_;
	static const int nb_bits_ = 8;
};

#endif