#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string name = "Slave");
	Peon(Peon const &);
	~Peon();
	Peon &operator=(Peon const &);
	void getPolymorphed() const;
};

#endif