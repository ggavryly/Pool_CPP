//
// Created by Gennady GAVRYLYSHYN on 2019-10-09.
//

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {

}

Intern::NotExist::NotExist(const Intern::NotExist &)
{}

Intern::NotExist::~NotExist() _NOEXCEPT
{}

Form* Intern::makeForm(std::string const &name, std::string const &target)
{
	std::string Forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	if (Forms[0] == name)
		return new RobotomyRequestForm(target);
	else if (Forms[1] == name)
		return new ShrubberyCreationForm(target);
	else if (Forms[2] == name)
		return new PresidentialPardonForm(target);
	else
		throw Intern::NotExist();
}

Intern::NotExist::NotExist()
{

}


const char* Intern::NotExist::what() const _NOEXCEPT
{
	return "Does form don't exist";
}
