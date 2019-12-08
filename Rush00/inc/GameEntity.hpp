#ifndef GAME_ENTITY_HPP
# define GAME_ENTITY_HPP
# include <ncurses.h>
# include <iostream>
# include <sys/time.h>
# include <sys/ioctl.h>
# include "PlayerShip.hpp"
# include "EnemyShip.hpp"
# include "DeepSpace.hpp"
# include "Cartridge.hpp"
# include "EnemyBullet.hpp"
# define ENEMY_NUMBER 100
# define BULLET_COUNT 50
# define ENEMY_BULLET_COUNT 50
# define DEEP_SPACE_COUNT 500
# define PICTURE_SIZE 2
class GameEntity
{
public:
	GameEntity();
	GameEntity(GameEntity const &w);
	~GameEntity();
	void CreateWindow();
	GameEntity		&operator=(GameEntity const &w);
	void ReplaceScreen() const;
	void CheckCollisionAll();
	void Start();
	void UpdateFrame();
	void DestroyWindow();
	void Loop(int diff);
	void CheckPlayerShoot();
	void BodyLoop(int diff);
	unsigned int FrameCounter(timeval t1, timeval t2);
	void GenerateEnemy(int diff);
	void GenerateDeepSpace();
	void GenerateEnemyBullet(EnemyShip const &e);
	void GenerateBullet();
	void EnemyBulletCollision();
    void window_menu();
    void game_over();
    void selectlvl();
private:
		WINDOW			*_Win;
		int	_Points;
		int _WinW;
		int _WinH;
		int	_IsFly;
		int _LastInput;
		int _Curr_input;
		struct timeval	_TvalBefore;
		struct timeval	_TvalAfter;
		struct timeval	_SimpleTime;
		DeepSpace		*_BackGroundSpace;
		EnemyShip 		*_Enemies;
		PlayerShip		_Player;
		int	_FrameCocounter;
		Cartridge 			*_Bullet;
		EnemyBullet 	*_EnemyBullets;

		static int	_NumberBullet;
		static int	_NumberEnemyBullets;
		static int	_NumberBackGroundSpace;
		static int	_NumberEnemy;
};


#endif
