#include "Form.hpp"

int main()
{
	try {
		Form  a("28B", 149, 150);
		Bureaucrat b("Gena", 150);
		b.signForm(a);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}