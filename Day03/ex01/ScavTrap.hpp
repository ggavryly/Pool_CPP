#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
#include <iostream>
class ScavTrap
{
public:
	ScavTrap(std::string const & name = "KAKAK112");
	ScavTrap(ScavTrap const & name);
	~ScavTrap();
	ScavTrap &operator=(ScavTrap const & fr4g_tp);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void virusAttack(std::string const & target);
	void monkeyAttack(std::string const & target);
	void manipulatorAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer();
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