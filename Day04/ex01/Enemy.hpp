#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
class Enemy
{
private:
	int hit_points;
	std::string type_;
public:
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const &);
	Enemy &operator=(Enemy const &);
	virtual ~Enemy();
	std::string getType() const;
	int getHP() const;
	void setType(std::string const &);
	void setHP(int);
	virtual void takeDamage(int);
};

#endif