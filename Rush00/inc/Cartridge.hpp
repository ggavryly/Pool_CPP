#ifndef СARTRIDGE_HPP
# define СARTRIDGE_HPP
# include "Object.hpp"

class Cartridge : public virtual Object
{
public:
	Cartridge(Cartridge const &p);
	~Cartridge();
	void setIsVisible(bool);
	Cartridge();
	Cartridge &operator=(Cartridge const &w);
	bool getIsVisible() const;
	void PutInDeepSpace() const;
	void Movement(int, int, int, int);
private:
	bool _isVisible;
};


#endif
