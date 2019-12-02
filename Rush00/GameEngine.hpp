#ifndef GAME_ENGINE_HPP
# define GAME_ENGINE_HPP

#include <ncurses.h>
#include "ICharacter.hpp"
#include <iostream>
#include "Player.hpp"
class GameEngine
{
private:
	WINDOW *win;
	Player *player;
	size_t win_width;
	size_t win_height;
public:
	GameEngine();
	void DrawCharacters();
	void DrawBackground();
	void Loop();
	void RefreshScreen();
	void ClearWindow();
	~GameEngine();

};

#endif