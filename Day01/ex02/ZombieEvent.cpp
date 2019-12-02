#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(std::string const &  type)
{
	this->type_ = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *new_zombie = new Zombie;

	new_zombie->name_ = name;
	new_zombie->type_ = this->type_;
	return new_zombie;
}

void ZombieEvent::randomChump()
{
	std::string arr[] = {"Hennadii", "Ivan", "Igor", "Dimon", "Mikhail_Stepanich", "Yagami_Light"};
	Zombie rand_zombie;
	static int a = 0;

	std::srand(unsigned(std::time(nullptr)));
	rand_zombie.type_ = this->type_;
	rand_zombie.name_ = arr[(std::rand() + a) % 6];
	rand_zombie.announce();
	a++
}