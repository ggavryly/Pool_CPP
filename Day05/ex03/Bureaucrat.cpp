//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <fstream>

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &a) : _name(a.getName()) , _grade(a.getGrade())
{}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &a) {
	this->setGrade(a.getGrade());
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat& Bureaucrat::operator++() {
	this->_grade--;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
	Bureaucrat  tmp(this->_name, this->_grade);
	this->_grade--;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return tmp;
}

Bureaucrat& Bureaucrat::operator--() {
	this->_grade++;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return *this;
}

Bureaucrat Bureaucrat::operator--(int) {
	Bureaucrat  tmp(this->_name, this->_grade);
	this->_grade++;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return tmp;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException &) {
}

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(const Bureaucrat::GradeTooHighException &)
{
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is to high";
}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException &) {
}

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(const Bureaucrat::GradeTooLowException &)
{
	return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is to low";
}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << "<" << bureaucrat.getName() << ">, bureaucrat grade <" << bureaucrat.getGrade() << ">" << std::endl;
	return os;
}

void Bureaucrat::signForm(Form &a) {
	try
	{
		a.beSigned(*this);
		std::cout << "<" << this->_name << "> signs <" << a.getName() << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "<" << this->_name << "> cannot sign <" << a.getName() << "> because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form &a)
{
	try {
		if (this->getGrade() > a.getGradeToExecute())
			throw Bureaucrat::GradeTooLowException();
		if (!a.isSign())
			throw Form::NotSigned();
		std::cout << "<" << this->getName() << "> executes <" << a.getName() << ">" << std::endl;
		a.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << "Execute was failed because " << e.what() << std::endl;
	}

}
