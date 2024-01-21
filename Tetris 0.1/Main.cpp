
#include "TetrisGame.h"

int main()
{
	maximizeConsole();

	TetrisGame Game;
	Game.printLogo();
	//gotoxy(0, 0);
	Game.showMenu();
	
	
	gotoxy(0, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y_BOARD_1 + 2);
	return 0;
}