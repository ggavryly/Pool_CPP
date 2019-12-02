#include "SuperMutant.hpp"
#include <iostream>
SuperMutant::SuperMutant() : Enemy::Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int a)
{
	Enemy::takeDamage(a - 3);
}

SuperMutant::SuperMutant(SuperMutant const &a) : Enemy::Enemy(a)
{}

SuperMutant& SuperMutant::operator=(SuperMutant const &a)
{
	this->setType(a.getType());
	this->setHP(a.getHP());
	return *this;
}