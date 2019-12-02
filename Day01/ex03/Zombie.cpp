# include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << "<" << this->name_ << " (" << this->type_ << ")>  Braiiiiiiinnnssss..." << std::endl;
}