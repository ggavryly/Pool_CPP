# include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : name_(name), title_(title)
{
	std::cout << this->name_ << ", " << this->title_ << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &other)
{
	this->name_ = other.name_;
	this->title_ = other.title_;
	std::cout << this->name_ << ", " << this->title_ << ", is born !" << std::endl;
}

void Sorcerer::setName(std::string const &name)
{
	this->name_ = name;
}

void Sorcerer::setTitle(std::string const &title)
{
	this->title_ = title;
}

std::string Sorcerer::getName() const
{
	return this->name_;
}

std::string Sorcerer::getTitle() const
{
	return this->title_;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->name_ << ", " << this->title_ << ", is dead. Consequences will never be the same !" << std::endl;
}

void Sorcerer::polymorph(Victim const &other) const
{
	other.getPolymorphed();
}
std::ostream & operator<<(std::ostream & o, Sorcerer const &sorcerer)
{
	o << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
	return o;
}