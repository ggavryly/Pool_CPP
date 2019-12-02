# include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const &name) : Name(name)
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
	std::cout << "...ScavTrap Destructor..." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &iron)
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

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
			  << "> at range, causing <"<< this->Ranged_attack_damage <<"> points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
			  << "> at melee, causing <"<< this->Melee_attack_damage <<"> points of damage !" << std::endl;
}

void ScavTrap::virusAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
			  << "> with virus, causing <"<< this->Ranged_attack_damage <<"> points of damage !" << std::endl;
}

void ScavTrap::manipulatorAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
			  << "> with manipulator, causing <"<< this->Melee_attack_damage <<"> points of damage !" << std::endl;
}

void ScavTrap::monkeyAttack(std::string const &target)
{
	std::cout << this->Type << " <" << this->Name  << "> attacks <" << target
			  << "> with monkey, causing <"<< this->Melee_attack_damage <<"> points of damage !" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	this->Hit_points = ((this->Hit_points + amount) > 100) ? (100) : (this->Hit_points + amount);
	std::cout << "" << this->Type << " <" << this->Name << "> has been repaired " << (this->Hit_points - amount) << " Now I have <" << this->Hit_points << "> Hit points" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	int amount_tmp = amount;
	int reduced_dmg = ((amount_tmp - this->Armor_damage_reduction) < 0) ? (0) : (amount_tmp - this->Armor_damage_reduction);
	this->Hit_points = ((this->Hit_points - reduced_dmg) < 0) ? (0) : (this->Hit_points - reduced_dmg);
	std::cout << "" << this->Type << " <" << this->Name << "> has been taked " << reduced_dmg << " damage. Now I have <" << this->Hit_points << "> Hit points" << std::endl;
}

void ScavTrap::challengeNewcomer()
{
	static int a = 0;
	std::string challange[8] = {"Kill 50 Human enemies", "Earn 9,999,999 Dollars" ,"Shoot 100000 Times", "Buy 500 Items", "HeadHunter", "How Much For The Planet?", "I fired every bullet ever", "Self contained economy"};
	std::srand(std::time(NULL));
	std::cout << "You need to " << challange[(rand() + a) % 4] << " to get $" << challange[((rand() + a) % 4) + 4] << "$ achievement" << std::endl;
	a++;
}