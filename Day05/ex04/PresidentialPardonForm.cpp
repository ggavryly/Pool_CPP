//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
		: Form("PresidentialPardonForm", 25, 5)
{
	this->_target = name;
}

PresidentialPardonForm::~PresidentialPardonForm() {


}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : Form::Form(a)
{
	this->_target = a.getTarget();
}

void PresidentialPardonForm::execute(Bureaucrat const &a) const
{
	if (this->getGradeToExecute() < a.getGrade())
		throw Bureaucrat::GradeTooLowException();
	if (!this->isSign())
		throw Form::NotSigned();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"<< std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::setTarget(const std::string &target) {
	_target = target;
}