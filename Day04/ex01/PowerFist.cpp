#include "PowerFist.hpp"

PowerFist::PowerFist(PowerFist const &other) : AWeapon::AWeapon(other)
{}

PowerFist::PowerFist() : AWeapon::AWeapon("Power Fist", 8, 50)
{}

PowerFist::~PowerFist()
{}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist& PowerFist::operator=(PowerFist const &other)
{
	this->setAPCost(other.getAPCost());
	this->setDamage(other.getDamage());
	this->setName(other.getName());
	return *this;
}