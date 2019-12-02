# include "FragTrap.hpp"

int main(void)
{
	FragTrap a("Gena");
	a.takeDamage(50);
	a.takeDamage(60);
	a.rangedAttack("Kaka");
	a.meleeAttack("Kaka");
	a.vaulthunter_dot_exe("1");
	a.vaulthunter_dot_exe("2");
	a.vaulthunter_dot_exe("2");
	a.vaulthunter_dot_exe("2");
	a.vaulthunter_dot_exe("2");
	a.beRepaired(60);
	a.beRepaired(60);
	return 0;
}