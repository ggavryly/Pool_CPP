# include <ncurses.h>
# include <curses.h>
# include <sys/time.h>
# include <sys/ioctl.h>
# include <iostream>
# include "Player.hpp"
# include <ctime>
# include "GameEngine.hpp"

int main()
{
	GameEngine a;

	a.Loop();
	return 0;

}
