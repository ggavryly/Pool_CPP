# ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant();
	SuperMutant(SuperMutant const &);
	SuperMutant &operator=(SuperMutant const &);
	virtual ~SuperMutant();
	void takeDamage(int);
};

#endif