# include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const &name) : Name(name)
{
	std::cout << "...ClapTrap Constructor..." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "...ClapTrap Destructor..." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &iron)
{
	this->Name = iron.Name;
	this->Hit_points = iron.Hit_points;
	this->Max_hit_points = iron.Max_hit_points;
	this->Energy_points = iron.Energy_points;
	this->Max_energy_points = iron.Energy_points;
	this->Level = iron.Level;
	this->Melee_attack_damage = iron.Melee_attack_damage;
	this->Ranged_attack_damage = iron.Ranged_attack_damage;
	this->Armor_damage_reduction = iron.Armor_damage_reduction;
	std::cout << "...ClapTrap Copy constructor..." << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &iron)
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
	std::cout << "...ClapTrap Assignation operator..." << std::endl;
	return *this;
}

void ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
			  << "> at range, causing <"<< this->Ranged_attack_damage <<"> points of damage !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
			  << "> at melee, causing <"<< this->Melee_attack_damage <<"> points of damage !" << std::endl;
}

void ClapTrap::virusAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
			  << "> with virus, causing <"<< this->Ranged_attack_damage <<"> points of damage !" << std::endl;
}

void ClapTrap::manipulatorAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
			  << "> with manipulator, causing <"<< this->Melee_attack_damage <<"> points of damage !" << std::endl;
}

void ClapTrap::monkeyAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
			  << "> with monkey, causing <"<< this->Melee_attack_damage <<"> points of damage !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->Hit_points = ((this->Hit_points + amount) > (unsigned)this->Max_hit_points) ? (this->Max_hit_points) : (this->Hit_points + amount);
	std::cout << "" << this->Type << " <" << this->Name << "> has been repaired " << (((int)(this->Hit_points - amount) < 0) ? (amount) : (this->Hit_points - amount)) << " Now I have <" << this->Hit_points << "> Hit points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int amount_tmp = amount;
	int reduced_dmg = ((amount_tmp - this->Armor_damage_reduction) < 0) ? (0) : (amount_tmp - this->Armor_damage_reduction);
	this->Hit_points = ((this->Hit_points - reduced_dmg) < 0) ? (0) : (this->Hit_points - reduced_dmg);
	std::cout << "" << this->Type << " <" << this->Name << "> has been taked " << reduced_dmg << " damage. Now I have <" << this->Hit_points << "> Hit points" << std::endl;
}