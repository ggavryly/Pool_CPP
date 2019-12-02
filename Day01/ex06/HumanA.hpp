#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include <iostream>
# include "Weapon.hpp"
class HumanA
{
public:
	void attack();
	HumanA(std::string name, Weapon & weapon);
private:
	std::string name_;
	Weapon &weapon_;
};

#endif