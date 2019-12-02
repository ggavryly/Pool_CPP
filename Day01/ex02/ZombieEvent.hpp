#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP
# include "Zombie.hpp"
# include <iostream>
class ZombieEvent
{
public:
	void setZombieType(std::string const &  type);
	Zombie* newZombie(std::string name);
	void randomChump();

private:
	std::string type_;
};

#endif