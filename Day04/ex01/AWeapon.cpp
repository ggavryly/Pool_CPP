# include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : name_(name), ap_cost(apcost) , damage_(damage)
{}

AWeapon::AWeapon(AWeapon const &other)
{
	this->damage_ = other.damage_;
	this->ap_cost = other.ap_cost;
	this->name_ = other.name_;
}

AWeapon& AWeapon::operator=(AWeapon const &other)
{
	this->name_ = other.name_;
	this->ap_cost = other.ap_cost;
	this->damage_ = other.damage_;
	return *this;
}

AWeapon::~AWeapon()
{}

std::string AWeapon::getName() const
{
	return this->name_;
}

int AWeapon::getAPCost() const
{
	return this->ap_cost;
}

int AWeapon::getDamage() const
{
	return this->damage_;
}

void AWeapon::setAPCost(int a)
{
	this->ap_cost = a;
}

void AWeapon::setDamage(int a)
{
	this->damage_ = a;
}

void AWeapon::setName(std::string const &a)
{
	this->name_ = a;
}