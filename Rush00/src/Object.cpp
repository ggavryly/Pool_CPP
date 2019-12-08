#include "Object.hpp"

Object::Object() : _x(5), _y(5), _Form(" ") {

}

Object::Object(int x, int y) : _x(x), _y(y),  _Form(" ") {

}

Object::Object(Object const & src) : _x(src._x), _y(src._y), _Form(src._Form) {

}

Object::~Object() {

}

int Object::getX() const {
	return _x;
}

int Object::getY() const {
	return _y;
}

void Object::setX(int x){
	_x = x;
}

void Object::setY(int y){
	if (y < 3)
		y = 3;
	_y = y;
}

std::string Object::getForm() const {
	return _Form;
}

void Object::setForm(std::string const &a)
{
	this->_Form = a;
}

Object &Object::operator=(Object const & rhs) {

	if (this != &rhs) {
		_Form = rhs.getForm();
		_x = rhs.getX();
		_y = rhs.getY();
	}
	return *this;
}

void Object::PutInDeepSpace() const {
	mvprintw(_y, _x, _Form.c_str());
}