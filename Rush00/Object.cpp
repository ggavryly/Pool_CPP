//
// Created by Gennady GAVRYLYSHYN on 2019-10-06.
//

#include "Object.hpp"

Object::Object()
{

}

Object::~Object()
{
	this->curwin = nullptr;
}

Object::Object(WINDOW * win, int yc, int xc, char c)
{
	curwin = win;
	_pos_y = yc;
	_pos_x = xc;
	getmaxyx(curwin, _height, _width);
	keypad(curwin, true);
	_character = c;
}

Object::Object(Object const &src)
{
	*this = src;
}

Object& Object::operator=(Object const &src)
{
	this->setHeight(src.getHeight());
	this->setMaxHp(src.getMaxHp());
	this->setCurrHp(src.getCurrHp());
	this->setWidth(src.getWidth());
	this->setPosX(src.getPosX());
	this->setPosY(src.getPosY());
	this->setCharacter(src.getCharacter());
	this->setXmax(src.getXmax());
	this->setYmax(src.getYmax());
	return *this;
}

int Object::getPosX() const
{
	return _pos_x;
}

void Object::setPosX(int posX)
{
	_pos_x = posX;
}

int Object::getPosY() const
{
	return _pos_y;
}

void Object::setPosY(int posY)
{
	_pos_y = posY;
}

int Object::getWidth() const
{
	return _width;
}

void Object::setWidth(int width)
{
	_width = width;
}

int Object::getHeight() const
{
	return _height;
}

void Object::setHeight(int height)
{
	_height = height;
}

int Object::getXmax() const
{
	return Xmax;
}

void Object::setXmax(int xmax)
{
	Xmax = xmax;
}

int Object::getYmax() const
{
	return Ymax;
}

void Object::setYmax(int ymax)
{
	Ymax = ymax;
}

char Object::getCharacter() const
{
	return _character;
}

void Object::setCharacter(char character)
{
	this->_character = character;
}

int Object::getCurrHp() const
{
	return _curr_hp;
}

int Object::getMaxHp() const
{
	return _max_hp;
}

void Object::setCurrHp(int currHp)
{
	_curr_hp = currHp;
}

void Object::setMaxHp(int maxHp)
{
	_max_hp = maxHp;
}

void Object::display()
{
	mvwaddch(curwin, _pos_y, _pos_x, _character);
}


