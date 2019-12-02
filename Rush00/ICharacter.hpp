# ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP

#include <iostream>

class ICharacter
{
	virtual void attack() = 0;
	virtual std::string const &ship_str();
	virtual void move(int direction);
};

#endif