#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
public:
	Weapon(std::string const & a);
	std::string const & getType();
	void setType(std::string const &);
private:
	std::string type_;
};

#endif