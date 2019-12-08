#ifndef PLAYER_SHIP_HPP
# define PLAYER_SHIP_HPP
#include "Object.hpp"

class PlayerShip : public Object
{
public:
	PlayerShip();
	PlayerShip(PlayerShip const &p);
	void PutInDeepSpace() const;
	void Movement(int, int, int, int);
	void KeyDownUp(int key, int W, int H);
	void KeyLeftRight(int key, int W, int H);
	~PlayerShip();
	int GetHP() const;
	void SetHP(int newHp);
	PlayerShip &operator=(PlayerShip const &w);
private:
	int _HP;
};


#endif
