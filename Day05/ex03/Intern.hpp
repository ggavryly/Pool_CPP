//
// Created by Gennady GAVRYLYSHYN on 2019-10-09.
//

#ifndef PISCINE_INTERN_HPP
#define PISCINE_INTERN_HPP
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
class Intern {
	Intern &operator=(Intern const &);
public:
	class NotExist : public std::exception
	{
		NotExist operator=(NotExist const&);
	public:
		NotExist();
		NotExist(NotExist const &);
		virtual ~NotExist() _NOEXCEPT;
		const char * what() const _NOEXCEPT;
	};
	Intern();
	virtual ~Intern();
	Intern(Intern const &);
	Form *makeForm(std::string const &name, std::string const &target);
};


#endif //PISCINE_INTERN_HPP
