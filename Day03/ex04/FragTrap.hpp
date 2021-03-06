# ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap(std::string const & name = "KAKA112");
	FragTrap(FragTrap const & name);
	~FragTrap();
	FragTrap &operator=(FragTrap const & fr4g_tp);
	void rangedAttack(std::string const & target);
	void vaulthunter_dot_exe(std::string const & target);
};

#endif