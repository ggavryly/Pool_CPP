#ifndef A_WEAPON_HPP
# define A_WEAPON_HPP

#include <iostream>

class AWeapon
{
private:
	std::string name_;
	int ap_cost;
	int damage_;
public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const &);
	AWeapon &operator=(AWeapon const &);
	virtual ~AWeapon();
	std::string getName() const;
	int getAPCost() const;
	int getDamage() const;
	void setName(std::string const &);
	void setAPCost(int);
	void setDamage(int);
	virtual void attack() const = 0;
};

#endif
