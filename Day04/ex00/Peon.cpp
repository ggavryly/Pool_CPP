# include "Peon.hpp"

Peon::Peon(std::string name) : Victim::Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &other) : Victim::Victim(other)
{}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a cute pink pony !" << std::endl;
}