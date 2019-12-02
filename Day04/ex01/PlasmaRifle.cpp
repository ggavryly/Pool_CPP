# include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(PlasmaRifle const &other) : AWeapon::AWeapon(other)
{}

PlasmaRifle::PlasmaRifle() : AWeapon::AWeapon("Plasma Rifle", 5, 21)
{}

PlasmaRifle::~PlasmaRifle()
{}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const &other)
{
	this->setAPCost(other.getAPCost());
	this->setDamage(other.getDamage());
	this->setName(other.getName());
	return *this;
}