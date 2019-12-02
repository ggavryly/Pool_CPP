#include "Bureaucrat.hpp"





int main()
{
	try {
		Bureaucrat a("Gena", 1);
		std::cout << a <<std::endl;
		a.setGrade(0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}