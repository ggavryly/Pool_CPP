#include "Cartridge.hpp"

Cartridge::Cartridge() {
	_isVisible = false;
	_Form = "+";
}

Cartridge::Cartridge(Cartridge const & src) {
	*this = src;
}

Cartridge &Cartridge::operator=(Cartridge const & rhs) {

	if (this != &rhs)
	{
		_Form = rhs.getForm();
	}
	return *this;
}

Cartridge::~Cartridge() {

}

bool Cartridge::getIsVisible() const{
	return _isVisible;
}

void Cartridge::setIsVisible(bool b)
{
	_isVisible = b;
}

void Cartridge::PutInDeepSpace() const {
	attron(COLOR_PAIR(2));
	mvprintw(_y, _x, _Form.c_str());
	attroff(COLOR_PAIR(2));
}

void Cartridge::Movement(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	if(frameCounter % 1 == 0)
		_x++;
	if (_x > winW)
		_isVisible = false;
}