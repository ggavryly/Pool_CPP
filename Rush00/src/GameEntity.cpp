#include "GameEntity.hpp"

int GameEntity::_NumberEnemy = 0;
int GameEntity::_NumberBackGroundSpace = 0;
int GameEntity::_NumberBullet = 0;
int GameEntity::_NumberEnemyBullets = 0;

GameEntity::GameEntity() {
	system("pkill afplay");
	system("afplay src/star_wars.mp3 &> /dev/null &");
	_Enemies = new EnemyShip[ENEMY_NUMBER];
	_BackGroundSpace = new DeepSpace[DEEP_SPACE_COUNT];
	_Bullet = new Cartridge[BULLET_COUNT];
	_EnemyBullets = new EnemyBullet[ENEMY_BULLET_COUNT];
	_FrameCocounter = 0;
	_Points = 0;
	Start();
}

GameEntity::GameEntity(GameEntity const & src) {
	_FrameCocounter = 0;
	Start();
	*this = src;
}

GameEntity &GameEntity::operator=(GameEntity const & rhs)
{
	if (this != &rhs)
		return *this;
	return *this;
}

GameEntity::~GameEntity() {
	system("pkill afplay");
	DestroyWindow();
	endwin();
	delete[] _Enemies;
	delete[] _BackGroundSpace;
	delete[] _Bullet;
	delete[] _EnemyBullets;
	std::cout << "\\=== ZRADA ===/" << std::endl;
}

void	GameEntity::Start() {

	initscr();
	noecho();
	curs_set(false);
	cbreak();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	start_color();
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, nullptr);
	refresh();
	init_pair(0, COLOR_BLACK, COLOR_WHITE);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);

	CreateWindow();
	_Curr_input = ERR;
	_LastInput = ERR;
	_IsFly = true;
	gettimeofday(&_SimpleTime, nullptr);
}

unsigned int    GameEntity::FrameCounter(struct timeval t1, struct timeval t2) {
	return (unsigned int)((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec));
}

void	GameEntity::CreateWindow() {

	struct winsize size;
	ioctl(0, TIOCGWINSZ, &size);
	gettimeofday(&_TvalBefore, nullptr);
	_WinW = size.ws_col;
	_WinH = size.ws_row - PICTURE_SIZE;
	_Win = newwin(_WinH, _WinW, PICTURE_SIZE, 0);
	wrefresh(_Win);
}

void	GameEntity::DestroyWindow() {
	erase();
	wrefresh(_Win);
	delwin(_Win);
}

void	GameEntity::CheckCollisionAll()
{
	for (int i = 0; i < ENEMY_NUMBER; i++) {
		if (_Enemies[i].getIsVisible()
			&& _Player.getY() == _Enemies[i].getY()
			&& _Player.getX() == _Enemies[i].getX()){
			_IsFly = false;
		}
	}
}

void	GameEntity::CheckPlayerShoot()
{
	for (int i = 0; i < BULLET_COUNT; i++) {
		for (int j = 0; j < ENEMY_NUMBER; j++) {
			if (_Enemies[j].getIsVisible() && _Bullet[i].getIsVisible())
			{
				if (_Bullet[i].getX() == _Enemies[j].getX() && _Bullet[i].getY() == _Enemies[j].getY())
				{
					_Enemies[j].setIsVisible(false);
					_Bullet[i].setIsVisible(false);
					if (_Enemies[j].getForm() == "<->")
						_Points += 5000;
					else if(_Enemies[j].getForm() == "<=")
						_Points += 1000;
					else
						_Points += 50;
				}
			}
		}
	}
}

void	GameEntity::EnemyBulletCollision()
{
	for (int i = 0; i < ENEMY_BULLET_COUNT; i++) {
		if (_EnemyBullets[i].getIsVisible()
			&& _Player.getY() == _EnemyBullets[i].getY()
			&& _Player.getX() == _EnemyBullets[i].getX()){
			_Player.SetHP(_Player.GetHP() - 1);
			_EnemyBullets[i].setIsVisible(false);
			if (!_Player.GetHP())
				_IsFly = false;
		}
	}
}

void	GameEntity::UpdateFrame() {
	_Player.Movement(_LastInput, _WinH, _WinW, _FrameCocounter);
	EnemyBulletCollision();
	CheckCollisionAll();
	for (int i = 0; i < DEEP_SPACE_COUNT; i++) {
		if (_BackGroundSpace[i].getIsVisible()){
			_BackGroundSpace[i].Movement(0, _WinH, _WinW, _FrameCocounter);
		}
	}
	for (int i = 0; i < ENEMY_NUMBER; i++) {
		if (_Enemies[i].getIsVisible()){
			_Enemies[i].Movement(0, _WinH, _WinW, _FrameCocounter);
			CheckPlayerShoot();
			if (_FrameCocounter % 21 == 0)
				GenerateEnemyBullet(_Enemies[i]);
		}
	}
	CheckCollisionAll();
	for (int i = 0; i < BULLET_COUNT; i++) {
		if (_Bullet[i].getIsVisible()){
			_Bullet[i].Movement(0, _WinH, _WinW, _FrameCocounter);
		}
	}
	CheckPlayerShoot();
	for (int i = 0; i < ENEMY_BULLET_COUNT; i++) {
		if (_EnemyBullets[i].getIsVisible()){
			_EnemyBullets[i].Movement(0, _WinH, _WinW, _FrameCocounter);
		}
	}
	EnemyBulletCollision();
}

void	GameEntity::ReplaceScreen() const
{
	mvprintw(2, (int)(_WinW * 0.02), "POINTS: ");
	mvprintw(2, (int)(_WinW * 0.2), "%d", _Points);

	mvprintw(2, (int)(_WinW * 0.85), "HP: ");
	mvprintw(2, (int)(_WinW * 0.90), "%d", _Player.GetHP());
	for (int i = 0; i < DEEP_SPACE_COUNT; i++) {
		if (_BackGroundSpace[i].getIsVisible()){
			_BackGroundSpace[i].PutInDeepSpace();
		}
	}
	for (int i = 0; i < ENEMY_NUMBER; i++) {
		if (_Enemies[i].getIsVisible()){
			_Enemies[i].PutInDeepSpace();
		}
	}
	_Player.PutInDeepSpace();
	for (int i = 0; i < BULLET_COUNT; i++) {
		if (_Bullet[i].getIsVisible()){
			_Bullet[i].PutInDeepSpace();
		}
	}
	for (int i = 0; i < ENEMY_BULLET_COUNT; i++) {
		if (_EnemyBullets[i].getIsVisible()){
			_EnemyBullets[i].PutInDeepSpace();
		}
	}
}

void			GameEntity::GenerateEnemy(int diff)
{
	_NumberEnemy++;
	if (!_Enemies[_NumberEnemy % ENEMY_NUMBER].getIsVisible() &&
			!(FrameCounter(_SimpleTime, _TvalAfter) % clock() % diff))
	{
		_Enemies[_NumberEnemy % ENEMY_NUMBER].setIsVisible(true);
		_Enemies[_NumberEnemy % ENEMY_NUMBER].setX(_WinW);
		_Enemies[_NumberEnemy % ENEMY_NUMBER].setY((unsigned int)(clock() % (_WinH)));
		_Enemies[_NumberEnemy % ENEMY_NUMBER]._isForward = _Enemies[_NumberEnemy % ENEMY_NUMBER].getY() < _WinH / 2;
	}
}

void			GameEntity::GenerateDeepSpace()
{
	_NumberBackGroundSpace++;
	if (!_BackGroundSpace[_NumberBackGroundSpace % DEEP_SPACE_COUNT].getIsVisible())
	{
		_BackGroundSpace[_NumberBackGroundSpace % DEEP_SPACE_COUNT].setIsVisible(true);
		_BackGroundSpace[_NumberBackGroundSpace % DEEP_SPACE_COUNT].setX(_WinW);
		_BackGroundSpace[_NumberBackGroundSpace % DEEP_SPACE_COUNT].setY((unsigned int)(clock() % (_WinH)));
	}
}

void			GameEntity::GenerateBullet()
{
	_NumberBullet++;
	if (!_Bullet[_NumberBullet % BULLET_COUNT].getIsVisible())
	{
		_Bullet[_NumberBullet % BULLET_COUNT].setIsVisible(true);
		_Bullet[_NumberBullet % BULLET_COUNT].setX(_Player.getX() + 1);
		_Bullet[_NumberBullet % BULLET_COUNT].setY(_Player.getY());
	}
}
void			GameEntity::GenerateEnemyBullet(EnemyShip const &e)
{
	if (clock() % 13 == 0 && e.getIsVisible())
	{
		_NumberEnemyBullets++;
		if (!_EnemyBullets[_NumberEnemyBullets % ENEMY_BULLET_COUNT].getIsVisible())
		{
			_EnemyBullets[_NumberEnemyBullets % ENEMY_BULLET_COUNT].setIsVisible(true);
			_EnemyBullets[_NumberEnemyBullets % ENEMY_BULLET_COUNT].setX(e.getX() - 1);
			_EnemyBullets[_NumberEnemyBullets % ENEMY_BULLET_COUNT].setY(e.getY());
		}
	}
}

void GameEntity::BodyLoop(int diff)
{
	DestroyWindow();
	CreateWindow();
	GenerateDeepSpace();
	GenerateEnemy(diff);
	if (_LastInput == ' ')
		GenerateBullet();
	UpdateFrame();
	ReplaceScreen();
	_TvalBefore = _TvalAfter;
	_FrameCocounter++;
	_LastInput = ERR;
}

void GameEntity::Loop(int diff)
{
	while (_IsFly)
	{
		_Curr_input = getch();
		if (_Curr_input == 'q' || _Curr_input == 'Q')
			return ;
		else if (_Curr_input != ERR)
			_LastInput = _Curr_input;
		gettimeofday(&_TvalAfter, nullptr);
		if (FrameCounter(_TvalBefore, _TvalAfter) >= 40000)
			this->BodyLoop(diff);
	}
}


void GameEntity::window_menu() {
    int choice;
    unsigned int highlight = 0;
    int row,col;
    getmaxyx(_Win, row,col);
    std::string choices[2] = {"Start Game", "Exit"};
    keypad(_Win, true);

    while(1)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            if(i == highlight)
                wattron(_Win, A_REVERSE | COLOR_PAIR(3));
            mvwprintw(_Win,(row / 2)+(i + 1),col/2,choices[i].c_str());
            wattroff(_Win, A_REVERSE);
        }
        choice = wgetch(_Win);
        switch(choice)
        {
            case KEY_UP:
                highlight--;
                break;
            case  KEY_DOWN:
                highlight++;
                break;
            default:
                break;
        }
        if(choice == 10)
            break;

    }
    if(highlight == 0)
        selectlvl();


}

void GameEntity::selectlvl()
{
    int choice;
    unsigned int highlight = 0;
    int row,col;
    getmaxyx(_Win, row,col);
    std::string choices[2] = {"Easy", "Today You Die"};
    keypad(_Win, true);
    wclear(_Win);
    while(1)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            if(i == highlight)
                wattron(_Win, A_REVERSE | COLOR_PAIR(3));
            mvwprintw(_Win,(row / 2)+(i + 1),col/2,choices[i].c_str());
            wattroff(_Win, A_REVERSE);
        }
        choice = wgetch(_Win);
        switch(choice)
        {
            case KEY_UP:
                highlight--;
                break;
            case  KEY_DOWN:
                highlight++;
                break;
            default:
                break;
        }
        if(choice == 10)
            break;

    }
    if(highlight == 0)
    {
    	for (int i = 0; i < DEEP_SPACE_COUNT; i++)
    		this->_BackGroundSpace[i].setForm("*");
        Loop(10);
    }
    else if(highlight == 1)
    {
    	for (int i = 0; i < DEEP_SPACE_COUNT; i++)
    		this->_BackGroundSpace[i].setForm("_*_");
        Loop(1);
    }
}