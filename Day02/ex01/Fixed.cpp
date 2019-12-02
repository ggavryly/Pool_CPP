# include "Fixed.hpp"
# include <cmath>
Fixed::Fixed() : value_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &value) : value_(value << Fixed::nb_bits_)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value_ = (int)roundf(value * (1 << Fixed::nb_bits_));
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value_ = other.value_;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value_;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value_ = raw;
}

float Fixed::toFloat() const
{
	return (this->value_ / (float)(1 << Fixed::nb_bits_));
}

int Fixed::toInt() const
{
	return (this->value_ >> Fixed::nb_bits_);
}

Fixed& Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value_ = other.value_;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

std::ostream & operator<<(std::ostream &o, Fixed const & a)
{
	o << a.toFloat();
	return o;
}