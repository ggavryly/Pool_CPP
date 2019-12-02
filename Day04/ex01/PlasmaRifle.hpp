#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &);
	PlasmaRifle &operator=(PlasmaRifle const &);
	virtual ~PlasmaRifle();
	void attack() const ;
};

#endif