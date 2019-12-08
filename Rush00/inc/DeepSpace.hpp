#ifndef DEEP_SPACE_HPP
# define DEEP_SPACE_HPP
#include "Object.hpp"

class DeepSpace: public virtual Object
		{

public:
	DeepSpace();
	DeepSpace(DeepSpace const &p);
	void setIsVisible(bool);
	void Movement(int, int, int, int);
	DeepSpace &operator=(DeepSpace const &w);
	bool getIsVisible() const;
	~DeepSpace();
private:
	bool _isVisible;
};

#endif