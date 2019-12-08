#include "PlayerShip.hpp"

PlayerShip::PlayerShip() {
	_Form = "}";
	_HP = 5;
}

PlayerShip::PlayerShip(PlayerShip const & src)
{
	*this = src;
}

PlayerShip::~PlayerShip() {

}
void PlayerShip::PutInDeepSpace() const {
	attron(COLOR_PAIR(2));
	mvprintw(_y, _x, _Form.c_str());
	attroff(COLOR_PAIR(2));
}

int PlayerShip::GetHP() const {
	return _HP;
}


void PlayerShip::KeyDownUp(int key, int W, int H)
{
	if ((key == KEY_DOWN || key == 's' || key == 'S') && _y < H)
		_y++;
	else if ((key == KEY_UP || key == 'w' || key == 'W') && _y > 3)
		_y--;
	(void)W;
}

void PlayerShip::KeyLeftRight(int key, int W, int H)
{
	if ((key == KEY_LEFT || key == 'a' || key == 'A') && _x > 1)
		_x--;
	else if ((key == KEY_RIGHT || key == 'd' || key == 'D') && _x < W - 2)
		_x++;
	(void)H;
}

void PlayerShip::Movement(int key, int win_H, int win_W, int frameCounter)
{
	if (frameCounter)
	{
		if ((key == KEY_DOWN || key == 's' || key == 'S') && _y < win_H)
			this->KeyDownUp(key, win_W, win_H);
		else if ((key == KEY_UP || key == 'w' || key == 'W') && _y > 3)
			this->KeyDownUp(key, win_W, win_H);
		if ((key == KEY_LEFT || key == 'a' || key == 'A') && _x > 1)
			this->KeyLeftRight(key, win_W, win_H);
		else if ((key == KEY_RIGHT || key == 'd' || key == 'D') && _x < win_W - 2)
			this->KeyLeftRight(key, win_W, win_H);
	}
}

PlayerShip &PlayerShip::operator=(PlayerShip const & rhs)
		{

	if (this != &rhs)
		_Form = rhs.getForm();
	return *this;
}

void  PlayerShip::SetHP(int newHp)
{
	_HP = newHp;
}
