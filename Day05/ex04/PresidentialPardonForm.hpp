//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#ifndef PISCINE_PRESIDENTIALPARDONFORM_HPP
#define PISCINE_PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	PresidentialPardonForm &operator=(PresidentialPardonForm const &a);
	std::string _target;
public:
	const std::string &getTarget() const;

	void setTarget(const std::string &target);

public:
	PresidentialPardonForm(const std::string &name);

	PresidentialPardonForm(const PresidentialPardonForm & a);
	virtual ~PresidentialPardonForm();
	void execute(Bureaucrat const &) const;
};


#endif //PISCINE_PRESIDENTIALPARDONFORM_HPP
