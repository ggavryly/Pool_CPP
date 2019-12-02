#ifndef SUPER_TRAP_HPP
# define SUPER_TRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public virtual NinjaTrap, public virtual FragTrap
{
public:
	SuperTrap(std::string const & name = "KAKA112");
	SuperTrap(SuperTrap const & name);
	~SuperTrap();
	SuperTrap &operator=(SuperTrap const & fr4g_tp);
};

#endif