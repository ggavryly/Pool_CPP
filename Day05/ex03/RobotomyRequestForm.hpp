//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#ifndef PISCINE_ROBOTOMYREQUESTFORM_HPP
#define PISCINE_ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	RobotomyRequestForm &operator=(RobotomyRequestForm const &a);
	std::string _target;
public:
	const std::string &getTarget() const;

	void setTarget(const std::string &target);

public:
		RobotomyRequestForm(const std::string &name);
		RobotomyRequestForm(const RobotomyRequestForm & a);
		virtual ~RobotomyRequestForm();
		void execute(Bureaucrat const &) const;
};


#endif //PISCINE_ROBOTOMYREQUESTFORM_HPP
