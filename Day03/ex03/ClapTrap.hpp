#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
class ClapTrap
{
public:
	ClapTrap(std::string const & name = "KAKA112");
	ClapTrap(ClapTrap const & name);
	~ClapTrap();
	ClapTrap &operator=(ClapTrap const & fr4g_tp);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void virusAttack(std::string const & target);
	void monkeyAttack(std::string const & target);
	void manipulatorAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
protected:
	std::string Name;
	std::string Type;
	int Hit_points;
	int Max_hit_points;
	int Energy_points;
	int Max_energy_points;
	int Level;
	int Melee_attack_damage;
	int Ranged_attack_damage;
	int Armor_damage_reduction;
};


#endif