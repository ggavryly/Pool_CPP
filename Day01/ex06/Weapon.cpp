#include "Weapon.hpp"

void Weapon::setType(std::string const &a)
{
	this->type_ = a;
}

std::string const& Weapon::getType()
{
	return this->type_;
}
Weapon::Weapon(std::string const & a)
{
	this->type_ = a;
}