#include "EnemyBullet.hpp"

EnemyBullet::EnemyBullet()
{
	_isVisible = false;
	_Form = "-";
}

EnemyBullet::EnemyBullet(EnemyBullet const & src)
{
	*this = src;
}

EnemyBullet::~EnemyBullet()
{

}
EnemyBullet &EnemyBullet::operator=(EnemyBullet const & rhs)
{

	if (this != &rhs)
	{
		_Form = rhs.getForm();
	}
	return *this;
}


bool EnemyBullet::getIsVisible() const
{
	return _isVisible;
}

void EnemyBullet::setIsVisible(bool b)
{
	_isVisible = b;
}
void EnemyBullet::Movement(int key, int winH, int winW, int frameCounter)
{
	(void)key;
	(void)winH;
	(void)winW;
	if(frameCounter % 1 == 0)
		_x--;
	if (_x < 0)
		_isVisible = false;
}

void EnemyBullet::PutInDeepSpace() const
{
	attron(COLOR_PAIR(1));
	mvprintw(_y, _x, _Form.c_str());
	attroff(COLOR_PAIR(1));

}

