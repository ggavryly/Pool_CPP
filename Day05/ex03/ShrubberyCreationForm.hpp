//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#ifndef PISCINE_SHRUBBERYCREATIONFORM_HPP
#define PISCINE_SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"


class ShrubberyCreationForm : public Form
{
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &a);

public:
	const std::string &getTarget() const;

	void setTarget(const std::string &target);

private:
	std::string _target;
public:
	ShrubberyCreationForm(const std::string &name);
	ShrubberyCreationForm(const ShrubberyCreationForm & a);
	virtual ~ShrubberyCreationForm();
	void execute(Bureaucrat const &) const;
};


#endif //PISCINE_SHRUBBERYCREATIONFORM_HPP
