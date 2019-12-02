#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

//int main()
//{
//	try {
//		Bureaucrat b("Gena", 73);
//		RobotomyRequestForm a("ivan");
//	}
//	catch (std::exception & e) {
//		std::cout << e.what() << std::endl;
//	}
//	return 0;
//}

static void signAndExecuteForms(Bureaucrat b, ShrubberyCreationForm f1, \
                    RobotomyRequestForm f2, PresidentialPardonForm f3)
{
	try
	{
		b.signForm(f1);
		b.signForm(f2);
		b.signForm(f3);

		b.executeForm(f1);
		b.executeForm(f2);
		b.executeForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

int main(void)
{
	Bureaucrat                    b1("B-1(69)", 69);
	Bureaucrat                    b2("B-2(42)", 42);
	Bureaucrat                    b3("B-3(1)", 1);
	ShrubberyCreationForm         f1("SCF_FORM");
	RobotomyRequestForm           f2("RRF_FORM");
	PresidentialPardonForm        f3("PDF_FORM");

	signAndExecuteForms(b1, f1, f2, f3);
	std::cout << std::endl;
	signAndExecuteForms(b2, f1, f2, f3);
	std::cout << std::endl;
	signAndExecuteForms(b3, f1, f2, f3);
	std::cout << std::endl;
	return (0);
}