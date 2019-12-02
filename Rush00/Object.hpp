//
// Created by Gennady GAVRYLYSHYN on 2019-10-06.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <iostream>
#include <ncurses.h>

class Object
{

public:
	Object();
	Object(Object const &src);
	Object(WINDOW * win, int yc, int xc, char c);
	Object &operator=(Object const &src);
	virtual ~Object();

	int getPosX() const;

	void setPosX(int posX);

	int getPosY() const;

	void setPosY(int posY);

	int getWidth() const;

	void setWidth(int width);

	int getHeight() const;

	void setHeight(int height);

	int getXmax() const;

	void setXmax(int xmax);

	int getYmax() const;

	void setYmax(int ymax);

	char getCharacter() const;

	void setCharacter(char character);

	int getCurrHp() const;

	int getMaxHp() const;

	void setCurrHp(int currHp);

	void setMaxHp(int maxHp);

	virtual void move(int key) = 0;
	void display();

protected:
	int _curr_hp;
	int _max_hp;
	int _pos_x;
	int _pos_y;
	int _width;
	int _height;
	int Xmax, Ymax;
	char _character;
	WINDOW *curwin;

};


#endif //PISCINE_OBJECT_HPP
