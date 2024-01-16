#include <conio.h> // for kbhit+getch
#include <iostream>
#include <Windows.h> // for Sleep and colors
using namespace std;

#include "general.h"
#include "gameConfig.h"
//#include "point.h"
#include "TetrisGame.h"

void main()
{
	TetrisGame::drawBorderForBoard();
	gotoxy(0, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y_BOARD_1 + 2);
}
