#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int
main(void)
{
	Form *FormOne;
	Form *FormTwo;
	Form *FormThree;
	Form *FormTest;
	Intern i1;
	Bureaucrat b1 = Bureaucrat("Mr. Abraham", 1);

	FormOne = i1.makeForm("robotomy request", "Gena");
	FormTwo = i1.makeForm("presidential pardon", "Gena");
	FormThree = i1.makeForm("shrubbery creation", "Gena");
	std::cout << *FormOne << std::endl;
	std::cout << *FormTwo << std::endl;
	std::cout << *FormThree << std::endl;

	b1.signForm(*FormTwo);
	b1.executeForm(*FormTwo);

	FormTest = i1.makeForm("TEST", "Marvin");

	return (0);
}