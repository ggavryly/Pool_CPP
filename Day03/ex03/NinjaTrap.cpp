# include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string const &name) : ClapTrap::ClapTrap(name)
{
	this->Type = "NNJA-TP";
	this->Hit_points = 60;
	this->Max_hit_points = 60;
	this->Energy_points = 120;
	this->Max_energy_points = 120;
	this->Level = 1;
	this->Melee_attack_damage = 60;
	this->Ranged_attack_damage= 5;
	this->Armor_damage_reduction= 0;
	std::cout << "...NinjaTrap Constructor..." << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	ClapTrap::~ClapTrap();
	std::cout << "...NinjaTrap Destructor..." << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &iron) : ClapTrap::ClapTrap(iron)
{
	std::cout << "...NinjaTrap Copy constructor..." << std::endl;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const &iron)
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
	std::cout << "...NinjaTrap Assignation operator..." << std::endl;
	return *this;
}

void NinjaTrap::ninjaShoebox(ClapTrap const &)
{
	std::cout << "IT'S HIDE NINJA CLAP_TRAP BOX" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap const &)
{
	std::cout << "IT'S HIDE NINJA FRAG_TRAP BOX" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap const &)
{
	std::cout << "IT'S HIDE NINJA SCAV_TRAP BOX" << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap const &)
{
	std::cout << "IT'S HIDE NINJA NINJA_TRAP SUPER BOX" << std::endl;
}