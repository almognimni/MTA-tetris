#include "Board.h"


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

bool Board::GetGameBoardValue(int x, int y) const
{
	return this->gameBoard[x][y];
}

bool Board::isOverlapping(const Tetrominoes& tetromino) const //19_01_24 maor made some changes in the h and cpp
{
	//int currentRotation = tetromino.getRotation(); -- **redundent**
	for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
	{
		int blockX = tetromino.GetBlockX(i);
		int blockY = tetromino.GetBlockY(i); //19/01/24 change GETBLOCK  to const function
		if (this->gameBoard[blockX][blockY])
		{
			return true;
		}
	}
	return false;
}

//Make "isTouching" function by the same principles
//Make a place function by the same principles
