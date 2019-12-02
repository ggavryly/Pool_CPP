//
// Created by Gennady GAVRYLYSHYN on 2019-10-08.
//

#ifndef PISCINE_BUREAUCRAT_HPP
#define PISCINE_BUREAUCRAT_HPP

#include <iostream>
class Form;

class Bureaucrat {
	Bureaucrat & operator=(Bureaucrat const&);
public:
	Bureaucrat(const std::string &name, int grade);
	const std::string	&getName() const;
	int 				getGrade() const;
	void				setGrade(int grade);
	void				signForm(Form &);
	Bureaucrat(Bureaucrat const &);
	Bureaucrat &operator++();
	Bureaucrat operator++(int);
	Bureaucrat &operator--();
	Bureaucrat operator--(int);
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
	~Bureaucrat();
private:
	const std::string	_name;
    int					_grade;
};


std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif //PISCINE_BUREAUCRAT_HPP
