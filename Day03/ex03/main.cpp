# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include "NinjaTrap.hpp"
int main(void)
{
	NinjaTrap a("gena");
	ClapTrap  b("1");
	FragTrap  c("2");
	ScavTrap  d("3");
	NinjaTrap  f("4");
	a.ninjaShoebox(b);
	a.ninjaShoebox(c);
	a.ninjaShoebox(d);
	a.ninjaShoebox(f);
	a.ninjaShoebox(a);
	a.takeDamage(59);
	a.takeDamage(150);
	a.beRepaired(150);
	return 0;
}