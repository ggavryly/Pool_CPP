#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"
class Sorcerer
{
public:
	Sorcerer(std::string name = "nothingness", std::string title = "");
	Sorcerer(Sorcerer const &);
	~Sorcerer();
	Sorcerer &operator=(Sorcerer const &);
	std::string getName() const;
	std::string getTitle() const;
	void setName(std::string const &);
	void setTitle(std::string const &);
	void polymorph(Victim const &) const;
protected:
	std::string name_;
	std::string title_;
};

std::ostream & operator<<(std::ostream & o, Sorcerer const &sorcerer);

#endif