# ifndef I_GAME_ENTITY_HPP
# define I_GAME_ENTITY_HPP

class IGameEntity
{
	virtual void move(int direction) = 0;
	virtual void takeDamage() = 0;
};

#endif