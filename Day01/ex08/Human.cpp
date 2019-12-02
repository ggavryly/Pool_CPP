#include "Human.hpp"

void Human::meleeAttack(std::string const &target)
{
	std::cout << "I Melee Attack to " << target << std::endl;
}

void Human::intimidatingShout(std::string const &target)
{
	std::cout << "I Intimidating Shout to " << target << std::endl;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << "I Ranged Attack to " << target << std::endl;
}



void Human::action(std::string const &action_name, std::string const &target)
{
	void (Human::*action[])(std::string const &target) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string action_names[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	for (size_t i = 0; i < 3; i++)
	{
		if (action_names[i] == action_name)
			(this->*action[i])(target);
	}
}
