#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
public:
	NinjaTrap(std::string const & name = "KAKA112");
	NinjaTrap(NinjaTrap const & name);
	~NinjaTrap();
	NinjaTrap &operator=(NinjaTrap const & fr4g_tp);
	void meleeAttack(std::string const &);
	void ninjaShoebox(FragTrap const &);
	void ninjaShoebox(ClapTrap const &);
	void ninjaShoebox(ScavTrap const &);
	void ninjaShoebox(NinjaTrap const &);
};

#endif