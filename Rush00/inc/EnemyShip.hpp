#ifndef ENEMY_SHIP_HPP
# define ENEMY_SHIP_HPP
#include "Object.hpp"

class EnemyShip: public virtual Object
{
public:
	EnemyShip(EnemyShip const &p);
	EnemyShip();
	~EnemyShip();
	void Movement(int, int, int, int);
	EnemyShip &operator=(EnemyShip const &w);
	bool getIsVisible() const;
	void setIsVisible(bool);
	bool _isForward;
	void PutInDeepSpace() const;
private:
	bool _isVisible;
};

#endif
