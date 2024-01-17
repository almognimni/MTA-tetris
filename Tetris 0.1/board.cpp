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
//int from start and add min_x_Board   17_1
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

void Board::printBlockInBoard(Block curBlock) 
{
	gotoxy(curBlock.getX(), curBlock.getY());
	cout << '*';
}

bool Board::isOverlapping(const Tetrominoes& tetromino)
{
	//int currentRotation = tetromino.getRotation(); -- **redundent**
	for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
	{
		int blockX = tetromino.GetBlockX(i);
		int blockY = tetromino.GetBlockY(i);
		if (this->gameBoard[blockX][blockY])
		{
			return true;
		}
	}
}

//Make "isTouching" function by the same principles
//Make a place function by the same principles
