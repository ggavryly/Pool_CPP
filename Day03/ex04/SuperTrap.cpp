#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string const &name)
{
	this->Type = "SPR-TP";
	this->Name = name;
	this->Hit_points = 100;
	this->Max_hit_points = 100;
	this->Energy_points = 120;
	this->Max_energy_points = 120;
	this->Level = 1;
	this->Melee_attack_damage = 60;
	this->Ranged_attack_damage= 20;
	this->Armor_damage_reduction= 5;
	std::cout << "...SuperTrap Constructor..." << std::endl;
}

SuperTrap::~SuperTrap()
{
	ClapTrap::~ClapTrap();
	std::cout << "...SuperTrap Destructor..." << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &iron) : ClapTrap::ClapTrap(iron)
{
	std::cout << "...SuperTrap Copy constructor..." << std::endl;
}

SuperTrap & SuperTrap::operator=(SuperTrap const &iron)
{
	this->Name = iron.Name;
	this->Hit_points = iron.Hit_points;
	this->Max_hit_points = iron.Max_hit_points;
	this->Energy_points = iron.Energy_points;
	this->Max_energy_points = iron.Max_energy_points;
	this->Level = iron.Level;
	this->Melee_attack_damage = iron.Melee_attack_damage;
	this->Ranged_attack_damage = iron.Ranged_attack_damage;
	this->Armor_damage_reduction = iron.Armor_damage_reduction;
	std::cout << "...SuperTrap Assignation operator..." << std::endl;
	return *this;
}
