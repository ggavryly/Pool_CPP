//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#ifndef PISCINE_FORM_HPP
#define PISCINE_FORM_HPP

#include <ostream>
#include "Bureaucrat.hpp"

class Form
{
	const std::string	_name;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
	bool				_sign;
	Form &operator=(Form const &);
public:
	Form(const std::string &name, const int gradeToSign, const int gradeToExecute);

	Form(Form const &);
	void beSigned(Bureaucrat const &);
	virtual ~Form();
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &);
		GradeTooHighException & operator=(GradeTooHighException const &);
		const char* what() const _NOEXCEPT;
		~GradeTooHighException() _NOEXCEPT;
	};
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const &);
		GradeTooLowException & operator=(GradeTooLowException const &);
		const char* what() const _NOEXCEPT;
		~GradeTooLowException() _NOEXCEPT;
	};
	class NotSigned : public std::exception
	{
	public:
		NotSigned();

		NotSigned(NotSigned const &);

		NotSigned & operator=(NotSigned const &);
		const char* what() const _NOEXCEPT;
		~NotSigned() _NOEXCEPT;
	};
	const std::string &getName() const;

	int getGradeToSign() const;

	int getGradeToExecute() const;

	bool isSign() const;

	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //PISCINE_FORM_HPP
