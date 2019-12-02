#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include <iostream>
# include "Weapon.hpp"
class HumanB
{
public:
	void attack();
	HumanB(std::string name);
	void setWeapon(Weapon & weapon);
private:
	std::string name_;
	Weapon *weapon_;
};
#endif