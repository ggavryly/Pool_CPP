# ifndef SQUAD_HPP
# define SQUAD_HPP
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <iostream>
class Squad : public ISquad
{
public:
	Squad();
	~Squad();
	Squad &operator=(Squad const &);
	Squad(Squad const &);
	int getCount() const;
	ISpaceMarine* getUnit(int) const;
	int push(ISpaceMarine*);
private:
	int num_units;
	int max_units;
	ISpaceMarine *squad_arr[30];
};

#endif