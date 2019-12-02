#include "Fixed.hpp"
int main( void )
{
//	Fixed a;
//	Fixed const b( Fixed(5.05f) * Fixed(2));
//	std::cout << a << std::endl;
//	std::cout << ++a << std::endl;
//	std::cout << a << std::endl;
//	std::cout << a++ << std::endl;
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//	std::cout << Fixed::max( a, b ) << std::endl;
	Fixed sraka('f' + 55.005f);
	std::cout << sraka << std::endl;
	std::cout << ++sraka-- << std::endl;
	std::cout << sraka << std::endl;
	return 0;
}