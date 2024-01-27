#include "Board.h"


using std::cout;
using std::cin;

void Board::deleteLine(int indexOfLineFromTop)
{
	clearLineChar(indexOfLineFromTop);
	makeLineFalse(indexOfLineFromTop);
	while (indexOfLineFromTop >= 1)
	{
		swapLineBoardAndColor(indexOfLineFromTop, indexOfLineFromTop - 1);
		indexOfLineFromTop--;
	}
}

bool Board::IsLineFull(int line)
{
	int j;
	for ( j = 0; j < GameConfig::GAME_WIDTH; j++)
	{					//Y,X
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
		this->gameBoardColor[indexOfLineFromTop][i] = 0; //BLACK BACKGROUND
	}
}
//first big 16 , second small 15
void Board::swapLineBoardAndColor(int firstLineFromTop, int secondLineFromTop)
{
	int i = 0;
	bool temp;
	for (i = 0; i < GameConfig::GAME_WIDTH; i++) //Board Swap
	{
		temp=this->gameBoard[firstLineFromTop][i];
		this->gameBoard[firstLineFromTop][i] = this->gameBoard[secondLineFromTop][i];
		this->gameBoard[secondLineFromTop][i] = temp;
	}
	char tempColor;
	for (i = 0; i < GameConfig::GAME_WIDTH; i++) //Board Color Swap
	{
		tempColor = this->gameBoardColor[firstLineFromTop][i];
		this->gameBoardColor[firstLineFromTop][i] = this->gameBoardColor[secondLineFromTop][i];
		this->gameBoardColor[secondLineFromTop][i] = tempColor;
	}
	//first smaill 15 , second big 16

	printTheSwap(secondLineFromTop,firstLineFromTop);
}
//int from start and add min_x_Board   17_1
void Board::clearLineChar(int indexOfLineFromTop)
{
    /* this code depned on what i get for location in the board - NEED TO DO
	gotoxy(numOfLineFromTheBottom + GameConfig::MIN_X_BOARD_1)
	*/

	gotoxy(this->printLocation, GameConfig::MIN_Y_BOARD_1 + indexOfLineFromTop);
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		cout << (char)GameConfig::EMPTYBOLCK;
	}
}
//first smaill 15 , second big 16
void Board::printTheSwap(int firstLineFromTop, int secondLineFromTop)
{	

	gotoxy(this->printLocation, GameConfig::MIN_Y_BOARD_1 + firstLineFromTop);
	printLineInBoard(firstLineFromTop);
	gotoxy(this->printLocation, GameConfig::MIN_Y_BOARD_1 + secondLineFromTop);
	printLineInBoard(secondLineFromTop);
	/*
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		gotoxy(this->printLocation, GameConfig::MIN_Y_BOARD_1 + firstLineFromTop);
		printLineInBoard(firstLineFromTop);

		
		gotoxy(this->printLocation +i, GameConfig::MIN_Y_BOARD_1 + firstLineFromTop);
		if (this->gameBoard[firstLineFromTop][i] == true)
		{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),GameConfig::COLORS[this->gameBoardColor[firstLineFromTop][i]]); //casting auto for char to int?
			cout << (char)GameConfig::BLOCK;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[8]);
			cout << (char)GameConfig::EMPTYBOLCK;
		}

			gotoxy(this->printLocation +i, GameConfig::MIN_Y_BOARD_1 + secondLineFromTop);
		if (this->gameBoard[secondLineFromTop][i] == true)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[this->gameBoardColor[secondLineFromTop][i]]);//casting auto for char to int?
			cout << (char)GameConfig::BLOCK;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[8]);
			cout << (char)GameConfig::EMPTYBOLCK;
		}
		
	}
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

bool Board::isOverlapping() const
{
	for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
	{
		int blockX = this->currentShape->GetBlockX(i);//memmory leak?
		int blockY = this->currentShape->GetBlockY(i);

		if (blockX < 0 || blockX >= GameConfig::GAME_WIDTH || blockY >= GameConfig::GAME_HEIGHT)
			return true;

		if (this->gameBoard[blockY][blockX] == true)
			return true;
	}
	return false;
}

bool Board::isOverlapping(GameConfig::eKeys direction) const
{
	
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
		int blockX = this->currentShape->GetBlockX(i, difRot) + difX;
		int blockY = this->currentShape->GetBlockY(i, difRot) + difY;

		if (blockX < 0 || blockX >= GameConfig::GAME_WIDTH || blockY >= GameConfig::GAME_HEIGHT)
			return true;

		if (this->gameBoard[blockY][blockX] == true)
			return true;
	}
	return false;
}

void Board::printShape(char charOfShape)
{
	if (this->gameWithColors == true)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[this->currentShape->getType() + 1]); //changed now 25/01

	//if (charOfShape == (char)GameConfig::EMPTYBOLCK)
	//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[8]);
	//else
	//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), currentShapeColor); //changed now 25/01

		for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
	{
		int blockX = this->currentShape->GetBlockX(i);
		int blockY = this->currentShape->GetBlockY(i);
		gotoxy(printLocation + blockX, GameConfig::MIN_Y_BOARD_1 + blockY);
		cout << charOfShape;
	}

}

void Board::generateTetromino() //consider a differant approch where we don't allocate memory (copy operator)
{
	this->currentShape = new Tetrominoes(); 
	this->shapeIsFalling = true;
}

void Board::placeTetromino()
{
	for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
	{
		int blockX = this->currentShape->GetBlockX(i);
		int blockY = this->currentShape->GetBlockY(i);
		this->gameBoard[blockY][blockX] = true;
		if (this->gameWithColors == true) //maor new
			this->gameBoardColor[blockY][blockX] = (this->currentShape->getType() + 1);
	}
}

void Board::moveCurrentShape(GameConfig::eKeys direction)
{  
	if (this->isShapeFalling() == false) // If there is no falling shape for the player at the momment, it has been placed and the temp shape is deleted
		return;

	if (this->isOverlapping(direction) == false)
	{
		this->printShape((char)GameConfig::EMPTYBOLCK);
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
		this->printShape((char)GameConfig::BLOCK);
	}

	else if (direction == GameConfig::eKeys::DROP)
	{
		shapeIsFalling = false;
		placeTetromino();
	}
}

void Board::reset()
{
	for (int i = 0; i < GameConfig::GAME_HEIGHT; i++)
	{
		for (int j = 0; j < GameConfig::GAME_WIDTH; j++)
		{
			this->gameBoard[i][j] = false;
			this->gameBoardColor[i][j] = 0;
		}
	}
	delete currentShape;
	shapeIsFalling = false;
}

void Board::printBoard()
{
	printBoardBoarders();

	for (int i = 0; i < GameConfig::GAME_HEIGHT; i++)
	{
		gotoxy(printLocation, GameConfig::MIN_Y_BOARD_1 + i);
		printLineInBoard(i);
	}

}

void Board::printLineInBoard(int line)
{
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		if (this->gameBoard[line][i] == true)
		{
			if(this->isColored()==true) //if game with color, choose the color
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[this->gameBoardColor[line][i]]);
			cout << (char)GameConfig::BLOCK;
		}
		else
		{
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[8]);
			cout << (char)GameConfig::EMPTYBOLCK;
		}
	}
}

void Board::printBoardBoarders()
{
	for (int col = printLocation; col <= GameConfig::GAME_WIDTH + printLocation; col++)
	{
		gotoxy(col, GameConfig::MIN_Y_BOARD_1 - 1);
		cout << "-";

		gotoxy(col, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y_BOARD_1);
		cout << "-";
	}

	for (int row = GameConfig::MIN_Y_BOARD_1 - 1; row <= GameConfig::GAME_HEIGHT + GameConfig::MIN_Y_BOARD_1; row++)
	{
		gotoxy(printLocation - 1, row);
		cout << "|";

		gotoxy(GameConfig::GAME_WIDTH + printLocation, row);
		cout << "|";
	}
}

void Board::deleteFullLines()
{
	int indexOfLineFromTop = GameConfig::GAME_HEIGHT - 1;
	while (indexOfLineFromTop >= 0)
	{
		if (IsLineFull(indexOfLineFromTop))
		{
			deleteLine(indexOfLineFromTop);
		}
		else
			indexOfLineFromTop--;
	}
}

