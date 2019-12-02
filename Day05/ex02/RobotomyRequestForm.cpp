//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &name)
		: Form("RobotomyRequestForm ", 72, 45)
{
	this->_target = name;
}

RobotomyRequestForm::~RobotomyRequestForm() {


}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) : Form::Form(a)
{
	this->_target = a.getTarget();
}

void RobotomyRequestForm::execute(Bureaucrat const &a) const
{
		static int b = 0;
		std::srand(std::time(nullptr));
		if (this->getGradeToExecute() < a.getGrade())
			throw Bureaucrat::GradeTooLowException();
		if (!this->isSign())
			throw Form::NotSigned();
		std::cout << "ZzZzza SHShhhhhhh Kreh HRECZx RRRRRrrrRRRrrrRRRRRRrRRRrrRrrRRRrRrRRrrRR" << std::endl;
		if ((rand() + b) % 2 == 0) {
			std::cout << this->getTarget() << " has been robotomized successfully 50%" << std::endl;
		}
		else
			std::cout << "it’s a failure" << std::endl;
		b++;
}

const std::string &RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::setTarget(const std::string &target) {
	_target = target;
}
