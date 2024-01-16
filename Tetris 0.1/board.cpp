#include "Board.h"
#include "gameConfig.h"
#include "General.h"
#include <iostream> 

using std::cout;
using std::cin;


void Board::makeLineFalse(int numOfLineFromTheBottom)
{
	int i = 0;
	for ( i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		this->gameBoard[numOfLineFromTheBottom][i] = false;
	}
}

void Board::swapLineFalse(int firstLineFromBottom, int secondLineFromBottom)
{
	int i = 0, temp;
	for (i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		temp=this->gameBoard[firstLineFromBottom][i];
		this->gameBoard[firstLineFromBottom][i] = this->gameBoard[secondLineFromBottom][i];
		this->gameBoard[secondLineFromBottom][i] = temp;
	}
}

void Board::clearLineChar(int numOfLineFromTheBottom)
{
/* this code depned on what i get for location in the board - NEED TO DO
	gotoxy(numOfLineFromTheBottom + GameConfig::MIN_X_BOARD_1)
	*/
}
void Board::swapLineChar(int firstLineFromBottom, int secondLineFromBottom)
{
	/* this code depned on what i get for location in the board - NEED TO DO
		gotoxy(numOfLineFromTheBottom + GameConfig::MIN_X_BOARD_1)
		*/
}

void Board::printBlockInBoard(int x, int y)
{
	gotoxy(x, y);
	cout << '*';
}
