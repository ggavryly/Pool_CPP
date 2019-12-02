#include "Character.hpp"

Character::Character(Character const &other)
{
	this->name = other.name;
	this->curr_weapon = other.curr_weapon;
	this->action_points = other.action_points;
	this->curr_weapon = nullptr;
}

Character::Character(std::string const &name)
{
	this->name = name;
	this->action_points = 40;
	this->curr_weapon = nullptr;
}

Character& Character::operator=(Character const &other)
{
	this->action_points = other.action_points;
	this->name = other.name;
	this->curr_weapon = other.curr_weapon;
	return *this;
}

std::string Character::getName() const
{
	return this->name;
}

void Character::setName(std::string const &a)
{
	this->name = a;
}

int Character::getAP() const
{
	return this->action_points;
}

AWeapon* Character::getWeapon() const
{
	return this->curr_weapon;
}

void Character::setWeapon(AWeapon *a)
{
	this->curr_weapon = a;
}

void Character::setAP(int a)
{
	this->action_points = a;
}

void Character::recoverAP()
{
	this->action_points += (this->action_points + 10) >= 40 ? (this->action_points - 10) : (10);
}

void Character::attack(Enemy *a)
{
	if (this->curr_weapon && (this->action_points - this->getWeapon()->getAPCost()) > 0)
	{
		std::cout << this->name << " attacks " << a->getType() << " with a "
				  << this->curr_weapon->getName() << " " << std::endl;
		this->getWeapon()->attack();
		a->takeDamage(this->curr_weapon->getDamage());
		this->action_points -= this->getWeapon()->getAPCost();
		if (a->getHP() == 0)
			delete a;
	}
}

void Character::equip(AWeapon *a)
{
	this->curr_weapon = a;
}

std::ostream & operator<<(std::ostream & o, Character const &s)
{
	if (s.getWeapon())
		o << s.getName() << " has " << s.getAP() << " and wields a " << s.getWeapon()->getName() << std::endl;
	else
		o << s.getName() << " has " << s.getAP() << " and is unarmed" << std::endl;
	return o;
}

