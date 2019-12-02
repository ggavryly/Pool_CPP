# include "FragTrap.hpp"

FragTrap::FragTrap(std::string const &name) : Name(name)
{
	this->Type = "FR4G-TP";
	this->Hit_points = 100;
	this->Max_hit_points = 100;
	this->Energy_points = 100;
	this->Max_energy_points = 100;
	this->Level = 1;
	this->Melee_attack_damage = 30;
	this->Ranged_attack_damage= 20;
	this->Armor_damage_reduction= 5;
	std::cout << "...FragTrap Constructor..." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "...FragTrap Destructor..." << std::endl;
}

FragTrap::FragTrap(FragTrap const &iron)
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
	std::cout << "...FragTrap Copy constructor..." << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const &iron)
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
	std::cout << "...FragTrap Assignation operator..." << std::endl;
	return *this;
}

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
	<< "> at range, causing <"<< this->Ranged_attack_damage <<"> points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
	<< "> at melee, causing <"<< this->Melee_attack_damage <<"> points of damage !" << std::endl;
}

void FragTrap::virusAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
	<< "> with virus, causing <"<< this->Ranged_attack_damage <<"> points of damage !" << std::endl;
}

void FragTrap::manipulatorAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
	<< "> with manipulator, causing <"<< this->Melee_attack_damage <<"> points of damage !" << std::endl;
}

void FragTrap::monkeyAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
	<< "> with monkey, causing <"<< this->Melee_attack_damage <<"> points of damage !" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	this->Hit_points = ((this->Hit_points + amount) > 100) ? (100) : (this->Hit_points + amount);
	std::cout << "" << this->Type << " <" << this->Name << "> has been repaired " << (this->Hit_points - amount) << " Now I have <" << this->Hit_points << "> Hit points" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	int amount_tmp = amount;
	int reduced_dmg = ((amount_tmp - this->Armor_damage_reduction) < 0) ? (0) : (amount_tmp - this->Armor_damage_reduction);
	this->Hit_points = ((this->Hit_points - reduced_dmg) < 0) ? (0) : (this->Hit_points - reduced_dmg);
	std::cout << "" << this->Type << " <" << this->Name << "> has been taked " << reduced_dmg << " damage. Now I have <" << this->Hit_points << "> Hit points" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->Energy_points >= 25)
	{
		static int a = 0;
		void (FragTrap::*action[])(std::string const &target) = {
				&FragTrap::meleeAttack,
				&FragTrap::rangedAttack,
				&FragTrap::virusAttack,
				&FragTrap::manipulatorAttack,
				&FragTrap::monkeyAttack};
		std::srand(std::time(NULL));
		(this->*action[(rand() + a) % 5])(target);
		a++;
		this->Energy_points -= 25;
	}
	else
		std::cout << "Not enough energy" << std::endl;
}
