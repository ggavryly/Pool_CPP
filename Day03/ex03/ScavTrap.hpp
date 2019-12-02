#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string const & name = "KAKA112");
	ScavTrap(ScavTrap const & name);
	~ScavTrap();
	ScavTrap &operator=(ScavTrap const & fr4g_tp);
	void challengeNewcomer();
};

#endif