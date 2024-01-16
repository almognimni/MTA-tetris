
#include "TetrisGame.h"
#include "general.h"
#include "gameConfig.h"

#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


void TetrisGame::drawBorderForBoard()
{
	for (int col = GameConfig::MIN_X_BOARD_1; col < GameConfig::GAME_WIDTH + GameConfig::MIN_X_BOARD_1; col++)
	{
		gotoxy(col, GameConfig::MIN_Y_BOARD_1 - 1);
		cout << "-";

		gotoxy(col, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y_BOARD_1);
		cout << "-";
	}

	for (int row = GameConfig::MIN_Y_BOARD_1 - 1; row <= GameConfig::GAME_HEIGHT + GameConfig::MIN_Y_BOARD_1; row++)
	{
		gotoxy(GameConfig::MIN_Y_BOARD_1 - 1, row);
		cout << "|";

		gotoxy(GameConfig::GAME_WIDTH + GameConfig::MIN_X_BOARD_1, row);
		cout << "|";
	}
}