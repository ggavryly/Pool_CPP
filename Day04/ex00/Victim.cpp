#include "Victim.hpp"

Victim::Victim(std::string name) : name_(name)
{
	std::cout << "Some random victim called " << this->name_ << " just popped !" << std::endl;
}

Victim::Victim(Victim const &other)
{
	this->name_ = other.name_;
	std::cout << this->name_ << ", " << ", is born !" << std::endl;
}

void Victim::setName(std::string const &name)
{
	this->name_ = name;
}


std::string Victim::getName() const
{
	return this->name_;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->name_ << " just died for no apparent reason !" << std::endl;
}

void Victim::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream & operator<<(std::ostream & o, Victim const &sorcerer)
{
	o << "I am " << sorcerer.getName() << " and I like otters !" << std::endl;
	return o;
}