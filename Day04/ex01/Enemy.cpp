# include "Enemy.hpp"

void Enemy::takeDamage(int a)
{
	if (a >= 0)
	{
		int tmp = (this->hit_points - a) < 0 ? (0) : this->hit_points - a;
		this->hit_points = tmp;
	}
}

Enemy::Enemy(Enemy const &other)
{
	this->type_ = other.type_;
	this->hit_points = other.hit_points;
}

Enemy& Enemy::operator=(Enemy const &other)
{
	this->hit_points = other.hit_points;
	this->type_ = other.type_;
	return *this;
}

Enemy::Enemy(int hp, std::string const &type)
{
	this->hit_points = hp;
	this->type_ = type;
}

int Enemy::getHP() const
{
	return this->hit_points;
}

std::string Enemy::getType() const
{
	return this->type_;
}

void Enemy::setHP(int a)
{
	this->hit_points = a;
}

void Enemy::setType(std::string const &type)
{
	this->type_ = type;
}

Enemy::~Enemy()
{}