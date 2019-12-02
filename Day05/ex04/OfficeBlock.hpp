//
// Created by Gennady GAVRYLYSHYN on 2019-10-09.
//

#ifndef PISCINE_OFFICEBLOCK_HPP
#define PISCINE_OFFICEBLOCK_HPP

#include "Bureaucrat.hpp"
#include "Intern.hpp"

class OfficeBlock
{
public:
	OfficeBlock(Bureaucrat *execBr, Bureaucrat *signBr, Intern *intern);
	OfficeBlock();
	virtual ~OfficeBlock();
	class NoSigner : public std::exception
	{
		NoSigner operator=(NoSigner const &);
	public:
		NoSigner();
		NoSigner(NoSigner const &);
		~NoSigner() _NOEXCEPT;
		const char * what() const _NOEXCEPT;
	};
	class NoExecutor : public std::exception
	{
		NoExecutor operator=(NoExecutor const &);
	public:
		NoExecutor();
		NoExecutor(NoExecutor const &);
		~NoExecutor() _NOEXCEPT;
		const char * what() const _NOEXCEPT;
	};
	class NoIntern : public std::exception
	{
		NoIntern operator=(NoIntern const &);
	public:
		NoIntern();
		NoIntern(NoIntern const &);
		~NoIntern() _NOEXCEPT;
		const char * what() const _NOEXCEPT;
	};
	class Monkey : public std::exception
	{
		Monkey operator=(Monkey const &);
	public:
		Monkey();
		Monkey(Monkey const &);
		~Monkey() _NOEXCEPT;
		const char * what() const _NOEXCEPT;
	};
	void doBureaucracy(std::string const &form, std::string const&target);

	Bureaucrat *getExecutor() const;

	void setExecutor(Bureaucrat &executor);

	Bureaucrat *getSigner() const;

	void setSigner(Bureaucrat &signer);

	Intern *getIntern() const;

	void setIntern(Intern &intern);

private:

	Bureaucrat	*_executor;
	Bureaucrat	*_signer;
	Intern		*_intern;
};


#endif //PISCINE_OFFICEBLOCK_HPP
