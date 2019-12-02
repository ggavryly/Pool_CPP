# include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : ClapTrap::ClapTrap(name)
{
	this->Type = "SCV-TP";
	this->Hit_points = 100;
	this->Max_hit_points = 100;
	this->Energy_points = 50;
	this->Max_energy_points = 50;
	this->Level = 1;
	this->Melee_attack_damage = 20;
	this->Ranged_attack_damage= 15;
	this->Armor_damage_reduction= 3;
	std::cout << "...ScavTrap Constructor..." << std::endl;
}

ScavTrap::~ScavTrap()
{
	ClapTrap::~ClapTrap();
	std::cout << "...ScavTrap Destructor..." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &iron) : ClapTrap::ClapTrap(iron)
{
	std::cout << "...ScavTrap Copy constructor..." << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &iron)
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
	std::cout << "...ScavTrap Assignation operator..." << std::endl;
	return *this;
}

void ScavTrap::challengeNewcomer()
{
	static int a = 0;
	std::string challange[8] = {"Kill 50 Human enemies", "Earn 9,999,999 Dollars" ,"Shoot 100000 Times", "Buy 500 Items", "HeadHunter", "How Much For The Planet?", "I fired every bullet ever", "Self contained economy"};
	std::srand(std::time(NULL));
	std::cout << "You need to " << challange[(rand() + a) % 4] << " to get $" << challange[((rand() + a) % 4) + 4] << "$ achievement" << std::endl;
	a++;
}