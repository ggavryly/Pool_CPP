# include "FragTrap.hpp"

FragTrap::FragTrap(std::string const &name) : ClapTrap::ClapTrap(name)
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
	ClapTrap::~ClapTrap();
	std::cout << "...FragTrap Destructor..." << std::endl;
}

FragTrap::FragTrap(FragTrap const &iron) : ClapTrap::ClapTrap(iron)
{
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
	std::cout << this->Type << " FRAG_TRAP <" << this->Name  << "> attacks <" << target
			  << "> at range, causing <"<< this->Ranged_attack_damage <<"> points of damage !" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->Energy_points >= 25)
	{
		static int a = 0;
		void (ClapTrap::*action[])(std::string const &target) = {
				&ClapTrap::meleeAttack,
				&ClapTrap::rangedAttack,
				&ClapTrap::virusAttack,
				&ClapTrap::manipulatorAttack,
				&ClapTrap::monkeyAttack};
		std::srand(std::time(NULL));
		(this->*action[(rand() + a) % 5])(target);
		a++;
		this->Energy_points -= 25;
	}
	else
		std::cout << "Not enough energy" << std::endl;
}
