#include "Player.hpp"

Player::Player(Player const &src) : Object::Object(src)
{
}

Player::~Player()
{

}

Player::Player()
{
}

Player::Player(WINDOW * win, int yc, int xc, char c) : Object::Object(win, yc, xc, c)
{}

void Player::mvup()
{
	mvwaddch(curwin, _pos_y, _pos_x, ' ');
	_pos_y -= 1;
	if(_pos_y < 1)
		_pos_y = 1;
}

void Player::mvdown()
{
	mvwaddch(curwin, _pos_y, _pos_x, ' ');
	_pos_y += 1;
	if(_pos_y > Ymax-1)
		_pos_y = Ymax-1;
}

void Player::mvleft()
{
	mvwaddch(curwin, _pos_y, _pos_x, ' ');
	_pos_x -= 1;
	if(_pos_x < 1)
		_pos_x = 1;
}

void Player::mvright()
{
	mvwaddch(curwin, _pos_y, _pos_x, ' ');
	_pos_x += 1;
	if(_pos_x > Xmax-1)
		_pos_x = Xmax-1;
}

void Player::move(int key)
{
	this->Xmax = getmaxx(curwin);
	this->Ymax = getmaxy(curwin);
	switch(key)
	{
		case KEY_UP:
			mvup();
			break;
		case KEY_DOWN:
			mvdown();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_RIGHT:
			mvright();
			break;
		default:
			break;
	}
}


