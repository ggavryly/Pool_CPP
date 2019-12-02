#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
class Fixed
{
public:
	Fixed();
	Fixed(const  int &);
	Fixed(const  float &);
	Fixed(Fixed const &);
	~Fixed();
	Fixed &operator=(Fixed const &);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
private:
	int value_;
	static const int nb_bits_ = 8;
};

std::ostream &operator<<(std::ostream &, Fixed const &);

#endif