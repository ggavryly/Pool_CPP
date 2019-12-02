#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << this->name_ << " attacks with his " << this->weapon_.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon)
{
}