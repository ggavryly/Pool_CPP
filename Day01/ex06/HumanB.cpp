#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name_ = name;
	this->weapon_ = nullptr;
}

void HumanB::attack()
{
	std::cout << this->name_ << " attacks with his " << ((this->weapon_) ? (this->weapon_->getType()) : ("")) << std::endl;
}

void HumanB::setWeapon(Weapon & weapon)
{
	this->weapon_ = &weapon;
}