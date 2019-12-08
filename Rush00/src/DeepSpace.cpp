#include "DeepSpace.hpp"

DeepSpace::DeepSpace() {
	_isVisible = false;
	_Form = "*";
}

DeepSpace::DeepSpace(DeepSpace const & src) {
	*this = src;
}
void DeepSpace::Movement(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	(void)winW;
	if(frameCounter % 1 == 0)
		_x--;
	if (_x < 0)
		_isVisible = false;
}

DeepSpace &DeepSpace::operator=(DeepSpace const & rhs) {

	if (this != &rhs)
	{
		_Form = rhs.getForm();
	}
	return *this;
}

void DeepSpace::setIsVisible(bool b)
{
	_isVisible = b;
}
DeepSpace::~DeepSpace() {

}

bool DeepSpace::getIsVisible() const{
	return _isVisible;
}


