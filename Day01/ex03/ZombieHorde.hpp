# ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP
# include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int N);
	void announce();
	~ZombieHorde();

private:
	int amount_zombie;
	Zombie *zombies;
};

#endif