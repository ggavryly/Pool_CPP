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
	bool operator<(Fixed const &);
	bool operator<=(Fixed const &);
	bool operator>(Fixed const &);
	bool operator>=(Fixed const &);
	bool operator==(Fixed const &);
	bool operator!=(Fixed const &);
	Fixed & operator++();
	Fixed & operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	Fixed operator+(Fixed const &) const;
	Fixed operator-(Fixed const &) const;
	Fixed operator/(Fixed const &) const;
	Fixed operator*(Fixed const &) const;
	static Fixed const &min(Fixed const&, Fixed const &);
	static Fixed const &max(Fixed const&, Fixed const &);
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