#include "EnemyShip.hpp"

std::string darkForces[3] = {"<->", "<=", "#-#"};

EnemyShip::EnemyShip() {
	_isVisible = false;
	_isForward = false;
	_Form = darkForces[clock() % 3];
}

EnemyShip::EnemyShip(EnemyShip const & src) {
	*this = src;
}

EnemyShip &EnemyShip::operator=(EnemyShip const & rhs) {

	if (this != &rhs)
	{
		_Form = rhs.getForm();
	}
	return *this;
}

EnemyShip::~EnemyShip() {

}

bool EnemyShip::getIsVisible() const{
	return _isVisible;
}

void EnemyShip::setIsVisible(bool b)
{
	_isVisible = b;
}

void EnemyShip::PutInDeepSpace() const {
	if (_Form == "<->") {
		attron(COLOR_PAIR(1));
		mvprintw(_y, _x, _Form.c_str());
		attroff(COLOR_PAIR(1));
	}
	else if (_Form == "<=") {
		attron(COLOR_PAIR(3));
		mvprintw(_y, _x, _Form.c_str());
		attroff(COLOR_PAIR(3));
	}
	else if (_Form == "#-#") {
		attron(COLOR_PAIR(4));
		mvprintw(_y, _x, _Form.c_str());
		attroff(COLOR_PAIR(4));
	}
}

void EnemyShip::Movement(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	(void)winW;
	if(frameCounter % 3 == 0)
	{
		if (_Form == "<->") {
			_y += clock() % 2 ? 1 : (-1);
		} else if (_Form == "<="){
			if (_isForward)
				_y++;
			else
				_y--;
			if (_y < 0 || _y > winH)
				_isForward = !_isForward;
		}
			_x--;
	}
	if (_x < 0)
		_isVisible = false;
}