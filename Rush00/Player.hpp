# ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Object.hpp"
class Player : public Object
{
public:
	Player();
	~Player();
	Player(Player const &src);
	Player(WINDOW * win, int yc, int xc, char c);
	Player &operator=(Player const &src);
	void mvup();
	void mvdown();
	void mvleft();
	void mvright();
	void move(int key);
};
#endif