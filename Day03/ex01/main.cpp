# include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("Gena");
	a.takeDamage(50);
	a.takeDamage(60);
	a.challengeNewcomer();
	a.challengeNewcomer();
	a.challengeNewcomer();
	a.beRepaired(60);
	a.beRepaired(60);
	return 0;
}