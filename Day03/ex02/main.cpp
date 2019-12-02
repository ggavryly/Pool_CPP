# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
int main(void)
{
	FragTrap a("Igor");
	ScavTrap b ("Dimon");
	a.takeDamage(50);
	b.takeDamage(50);
	a.meleeAttack("1");
	b.meleeAttack("1");
	a.rangedAttack("2");
	b.rangedAttack("2");
	a.beRepaired(60);
	b.beRepaired(60);
	a.vaulthunter_dot_exe("3");
	a.vaulthunter_dot_exe("4");
	b.challengeNewcomer();
	b.challengeNewcomer();
	return 0;
}