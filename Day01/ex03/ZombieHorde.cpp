#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	std::string name[] = {"LITAYSHI MAKARON", "YI YBIL TVOEGO OTZA", "KAKA", "GOLOVA STALINA", "I UMER NO NE MOY PAMAT", "Rockzvezda",};
	this->zombies = new Zombie[N];
	this->amount_zombie = N;
	for (int i = 0; i < N; i++)
	{
		std::srand(std::time(NULL));
		this->zombies[i].name_ = name[(rand() + i) % 6];
		this->zombies[i].type_ = "Horde";
	}
}

void ZombieHorde::announce()
{
	for (int i = 0; i < this->amount_zombie; i++)
		this->zombies[i].announce();
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->zombies;
}