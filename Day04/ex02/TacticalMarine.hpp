# ifndef TACTICAL_MARINE_HPP
# define TACTICAL_MARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>
class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const &);
	TacticalMarine &operator=(TacticalMarine const &);
	~TacticalMarine();
	TacticalMarine* clone() const;
	void battleCry() const ;
	void rangedAttack() const ;
	void meleeAttack() const ;
};

#endif