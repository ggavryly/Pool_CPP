//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#include "Form.hpp"

const std::string &Form::getName() const {
	return _name;
}

int Form::getGradeToSign() const {
	return _grade_to_sign;
}
int Form::getGradeToExecute() const {
	return _grade_to_execute;
}

bool Form::isSign() const {
	return _sign;
}

void Form::beSigned(Bureaucrat const &a)
{
	if (_grade_to_sign < a.getGrade())
		throw Form::GradeTooLowException();
	else {
		this->_sign = true;
	}
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute) : _name(name),
																					   _grade_to_sign(gradeToSign),
																					   _grade_to_execute(
																							   gradeToExecute)
{
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	this->_sign = false;
}
Form::Form(Form const &a) : _name(a.getName()), _grade_to_sign(a.getGradeToSign()), _grade_to_execute(a.getGradeToExecute())
{
	if (a.getGradeToExecute() > 150 || a.getGradeToSign() > 150)
		throw GradeTooLowException();
	if (a.getGradeToExecute() < 1 || a.getGradeToSign() < 1)
		throw GradeTooHighException();
	this->_sign = a.isSign();
}

Form& Form::operator=(Form const &a)
{
	(void)a;
	return *this;
}


Form::GradeTooHighException::GradeTooHighException()
{
}

Form::GradeTooHighException::GradeTooHighException(const Form::GradeTooHighException &) {
}

Form::GradeTooHighException& Form::GradeTooHighException::operator=(const Form::GradeTooHighException &)
{
	return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is to high";
}
Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

Form::GradeTooLowException::GradeTooLowException() {
}

Form::GradeTooLowException::GradeTooLowException(const Form::GradeTooLowException &) {
}

Form::GradeTooLowException& Form::GradeTooLowException::operator=(const Form::GradeTooLowException &)
{
	return *this;
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is to low";
}
Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

Form::NotSigned::NotSigned() {
}

Form::NotSigned::NotSigned(const Form::NotSigned &) {
}

Form::NotSigned& Form::NotSigned::operator=(const Form::NotSigned &)
{
	return *this;
}

const char* Form::NotSigned::what() const throw() {
	return "Form not signed";
}
Form::NotSigned::~NotSigned() throw()
{
}


std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "<" << form.getName() << "> grade_to_sign: " << form.getGradeToSign() << " grade_to_execute: "
	   << form.getGradeToExecute() << " sign: " << form.isSign();
	return os;
}

Form::~Form() {}
