# ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"


class Character
{
private:
	std::string name;
	int action_points;
	AWeapon *curr_weapon;
public:
	Character(std::string const & name);
	Character(Character const &);
	Character &operator=(Character const &);
	~Character();
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	std::string getName() const;
	int getAP() const;
	AWeapon * getWeapon() const ;
	void setWeapon(AWeapon *);
	void setAP(int);
	void setName(std::string const &);
};

std::ostream & operator<<(std::ostream & o, Character const &s);

#endif