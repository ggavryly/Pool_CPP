#ifndef ENEMY_BULLET_HPP
# define ENEMY_BULLET_HPP
# include "Object.hpp"

class EnemyBullet : public virtual Object
		{
	
	public:
	EnemyBullet(EnemyBullet const &p);
	EnemyBullet();
	~EnemyBullet();
	void Movement(int, int, int, int);
	EnemyBullet &operator=(EnemyBullet const &w);
	bool getIsVisible() const;
	void setIsVisible(bool);
	void PutInDeepSpace() const;
	private:
	bool _isVisible;
};


#endif //
