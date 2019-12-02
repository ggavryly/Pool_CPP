#include "ZombieEvent.hpp"

int main(void)
{
	ZombieEvent Z_E;
	Z_E.setZombieType("Warrior");
	Zombie *Z = Z_E.newZombie("Makaroni na taralke");
	Z->announce();
	Z_E.randomChump();
	Z_E.setZombieType("Monk");
	Z_E.randomChump();
	delete Z;
}