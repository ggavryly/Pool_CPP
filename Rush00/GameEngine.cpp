#include "GameEngine.hpp"

GameEngine::GameEngine()
{
	initscr();
	this->win = newwin(500, 500, 0, 0);
	this->win_width = 500;
	this->win_height = 500;
	halfdelay(100);
	curs_set(FALSE);
	noecho();
	getmaxyx(this->win, win_height , win_width);
	this->player = new Player(this->win , 1, 1, '{');
	getch();
}

void GameEngine::RefreshScreen()
{
	wrefresh(this->win);
}

GameEngine::~GameEngine()
{
	delwin(this->win);
	delete this->player;
	endwin();
}

void GameEngine::ClearWindow()
{
	wclear(this->win);
}

void GameEngine::Loop()
{
	int action;

	while (true)
	{
		action = wgetch(this->win);
		if (action == KEY_UP || action == KEY_DOWN || action == KEY_LEFT || action == KEY_RIGHT)
			this->player->move(action);
		else if (action == 27)
			exit(0);
		else
		{

		}
		this->ClearWindow();
		box(this->win,0,0);
		this->player->display();
		this->RefreshScreen();
	}
}