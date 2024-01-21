#include "Board.h"


using std::cout;
using std::cin;

void Board::deleteLine(int indexOfLineFromTop)
{
	clearLineChar(indexOfLineFromTop);
	makeLineFalse(indexOfLineFromTop);
	while (indexOfLineFromTop >= 1)
	{
		swapLineFalse(indexOfLineFromTop, indexOfLineFromTop - 1);
		indexOfLineFromTop--;
	}
}

bool Board::IsLineFull(int line)
{
	int j;
	for ( j = 0; j < GameConfig::GAME_WIDTH; j++)
	{
		if (this->gameBoard[line][j] == 0)
			return false;
	}
	return true;
}
void Board::makeLineFalse(int indexOfLineFromTop)
{
	int i = 0;
	for ( i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		this->gameBoard[indexOfLineFromTop][i] = false;
	}
}

void Board::swapLineFalse(int firstLineFromTop, int secondLineFromTop)
{
	int i = 0;
	bool temp;
	for (i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		temp=this->gameBoard[firstLineFromTop][i];
		this->gameBoard[firstLineFromTop][i] = this->gameBoard[secondLineFromTop][i];
		this->gameBoard[secondLineFromTop][i] = temp;
	}
	printTheSwap(firstLineFromTop, secondLineFromTop);
}
//int from start and add min_x_Board   17_1
void Board::clearLineChar(int indexOfLineFromTop)
{
    /* this code depned on what i get for location in the board - NEED TO DO
	gotoxy(numOfLineFromTheBottom + GameConfig::MIN_X_BOARD_1)
	*/
	gotoxy(GameConfig::MIN_X_BOARD_1, GameConfig::MIN_Y_BOARD_1 + indexOfLineFromTop);
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		cout << ' ';
	}
}
void Board::printTheSwap(int firstLineFromTop, int secondLineFromTop)
{	
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		gotoxy(GameConfig::MIN_X_BOARD_1, GameConfig::MIN_Y_BOARD_1 + firstLineFromTop);
		if (this->gameBoard[firstLineFromTop][i] == true)
			cout << (char)219;
		else
			cout << ' ';
		gotoxy(GameConfig::MIN_X_BOARD_1, GameConfig::MIN_Y_BOARD_1 + secondLineFromTop);
		if (this->gameBoard[secondLineFromTop][i] == true)
			cout << (char)219;
		else
			cout << ' ';


	}
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

bool Board::isOverlapping() const
{
	for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
	{
		int blockX = this->currentShape->GetBlockX(i);//memmory leak?
		int blockY = this->currentShape->GetBlockY(i);

		if (blockX < 0 || blockX >= GameConfig::GAME_WIDTH || blockY >= GameConfig::GAME_HEIGHT)
			return true;

		if (this->gameBoard[blockX][blockY] == true)
			return true;
	}
	return false;
}

bool Board::isOverlapping(GameConfig::eKeys direction) const
{
	//int currentRotation = tetromino.getRotation(); -- **redundent**
	
	int difX = 0;
	int difY = 0;
	int difRot = 0;

	switch (direction)
	{
	case GameConfig::eKeys::DROP:
		difY++;
		break;

	case GameConfig::eKeys::RIGHT:
		difX++;
		break;

	case GameConfig::eKeys::LEFT:
		difX--;
		break;
	case GameConfig::eKeys::ROTATE_CLOCKWISE:
		difRot++;
		break;

	case GameConfig::eKeys::ROTATE_COUNTERCLOCKWISE:
		difRot--;
	break;
	}
	for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
	{
		int blockX = this->currentShape->GetBlockX(i, difRot) + difX;//memmory leak?
		int blockY = this->currentShape->GetBlockY(i, difRot) + difY;

		if (blockX < 0 || blockX >= GameConfig::GAME_WIDTH || blockY >= GameConfig::GAME_HEIGHT)
			return true;

		if (this->gameBoard[blockX][blockY] == true)
			return true;
	}
	return false;
}

void Board::printShape(char charOfShape) //Should we remove the shape parameter? WE JUST DIDDDDD
{
	for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
	{
		int blockX = this->currentShape->GetBlockX(i);
		int blockY = this->currentShape->GetBlockY(i);
		gotoxy(GameConfig::MIN_X_BOARD_1 + blockX, GameConfig::MIN_Y_BOARD_1 + blockY);
		cout << charOfShape;
	}
	
}

void Board::generateTetromino() //consider a differant approch where we don't allocate memory (copy operator)
{
	this->currentShape = new Tetrominoes(); 
}

void Board::placeTetromino()
{
	for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
	{
		int blockX = this->currentShape->GetBlockX(i);
		int blockY = this->currentShape->GetBlockY(i);
		this->gameBoard[blockX][blockY] = true;
	}
}

bool Board::moveCurrentShape(GameConfig::eKeys direction)
{
	bool isFalling = true;

	if (this->isOverlapping(direction) == false) //Need to update for rotations
	{
		this->printShape(' ');
		switch (direction)
		{
		case GameConfig::eKeys::DROP:
			this->currentShape->lower();
			break;
		case GameConfig::eKeys::RIGHT:
			this->currentShape->moveRight();
			break;
		case GameConfig::eKeys::LEFT:
			this->currentShape->moveLeft();
			break;
		
		case GameConfig::eKeys::ROTATE_CLOCKWISE:
			this->currentShape->rotateClockwise();
			break;

		case GameConfig::eKeys::ROTATE_COUNTERCLOCKWISE:
			this->currentShape->rotateCounterClockwise();
			break;
		}
		this->printShape((char)219);
	}

	else if (direction == GameConfig::eKeys::DROP)
	{
		isFalling = false;
		placeTetromino();
	}
	return isFalling;
}