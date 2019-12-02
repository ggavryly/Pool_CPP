# ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
#include "ICharacter.hpp"
class Enemy : ICharacter
{
private:
	std::string _ship;
	int _pos_x;
	int _pos_y;
	int _size;
public:
	Enemy(std::string const & = "		__\n"
							 	"        |\\\n"
								"        / \\\n"
								"       / =/\n"
								" (}-==( :[|\n"
								"       \\ =\\\n"
								"        \\ /\n"
								"      __|/");
	~Enemy();
};

#endif