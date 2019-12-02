//
// Created by Gennady GAVRYLYSHYN on 2019-10-09.
//

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(Bureaucrat *execBr, Bureaucrat *signBr, Intern *intern) : _executor(execBr), _signer(signBr),
																				   _intern(intern)
{}

OfficeBlock::OfficeBlock() {
	this->_intern = nullptr;
	this->_executor = nullptr;
	this->_signer = nullptr;
}

OfficeBlock::~OfficeBlock() {

}

OfficeBlock::NoExecutor::NoExecutor()
{
}

OfficeBlock::NoExecutor::NoExecutor(const OfficeBlock::NoExecutor &)
{}

OfficeBlock::NoExecutor::~NoExecutor() _NOEXCEPT
{}

const char* OfficeBlock::NoExecutor::what() const _NOEXCEPT
{
	return "no executor bureaucrat";
}

OfficeBlock::NoIntern::NoIntern()
{
}

OfficeBlock::NoIntern::NoIntern(const OfficeBlock::NoIntern &)
{}

OfficeBlock::NoIntern::~NoIntern() _NOEXCEPT
{}

const char* OfficeBlock::NoIntern::what() const _NOEXCEPT
{
	return "no intern";
}

OfficeBlock::NoSigner::NoSigner()
{
}

OfficeBlock::NoSigner::NoSigner(const OfficeBlock::NoSigner &)
{}

OfficeBlock::NoSigner::~NoSigner() _NOEXCEPT
{}

const char* OfficeBlock::NoSigner::what() const _NOEXCEPT
{
	return "no signer bureaucrat";
}

OfficeBlock::Monkey::Monkey()
{
}

OfficeBlock::Monkey::Monkey(const OfficeBlock::Monkey &)
{}

OfficeBlock::Monkey::~Monkey() _NOEXCEPT
{}

const char* OfficeBlock::Monkey::what() const _NOEXCEPT
{
	return "The monkey is not a legal entity.";
}

void OfficeBlock::doBureaucracy(std::string const &form, std::string const & target)
{
	if (target == "monkey" || target == "Monkey")
		throw OfficeBlock::Monkey();
	if (!_signer)
		throw OfficeBlock::NoSigner();
	if (!_executor)
		throw OfficeBlock::NoExecutor();
	if (!_intern)
		throw OfficeBlock::NoIntern();
	Form *NewForm = this->_intern->makeForm(form, target);
	_signer->signForm(*NewForm);
	_executor->executeForm(*NewForm);
	delete NewForm;
}

Bureaucrat *OfficeBlock::getExecutor() const {
	return _executor;
}

void OfficeBlock::setExecutor(Bureaucrat &executor) {
	_executor = &executor;
}

Bureaucrat *OfficeBlock::getSigner() const {
	return _signer;
}

void OfficeBlock::setSigner(Bureaucrat &signer) {
	_signer = &signer;
}

Intern *OfficeBlock::getIntern() const {
	return _intern;
}

void OfficeBlock::setIntern(Intern &intern) {
	_intern = &intern;
}

