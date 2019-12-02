//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#include "Bureaucrat.hpp"

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
	os << "<" << bureaucrat._name << ">, bureaucrat grade <" << bureaucrat._grade << ">" << std::endl;
	return os;
}
