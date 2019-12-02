#include "RadScorpion.hpp"
#include <iostream>
RadScorpion::RadScorpion() : Enemy::Enemy(80, "RadScorpion")
{
	std::cout << "“* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

void RadScorpion::takeDamage(int a)
{
	Enemy::takeDamage(a);
}

RadScorpion::RadScorpion(RadScorpion const &a) : Enemy::Enemy(a)
{}

RadScorpion& RadScorpion::operator=(RadScorpion const &a)
{
	this->setType(a.getType());
	this->setHP(a.getHP());
	return *this;
}