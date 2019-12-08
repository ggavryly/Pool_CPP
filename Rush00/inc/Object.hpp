#ifndef OBJECT_HPP
# define OBJECT_HPP
# include <ncurses.h>
# include <string>

class Object
{
public:
	int getY() const;
	void setX(int);
	std::string getForm() const;
	void setForm(std::string const &);
	Object();
	void setY(int);
	int getX() const;
	Object(int x, int y);
	virtual void Movement(int, int, int, int) = 0;
	virtual ~Object();
	Object &operator=(Object const & win);
	Object(Object const & win);
	virtual void PutInDeepSpace() const;
protected:
	int _x;
	int _y;
	std::string _Form;
};


#endif
