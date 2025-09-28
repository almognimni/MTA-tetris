#include "Board.h"


using std::cout;
using std::cin;

/**
 * @brief Deletes a completed line and shifts all lines above it downward
 * @param indexOfLineFromTop Zero-based index of the line to delete from the top
 * 
 * This function implements the core Tetris line-clearing mechanic:
 * 1. Clears the visual representation of the line
 * 2. Sets all positions in the line to false (empty)
 * 3. Shifts all lines above the deleted line down by one position
 */
void Board::deleteLine(int indexOfLineFromTop)
{
	clearLineChar(indexOfLineFromTop);           // Clear visual display
	makeLineFalse(indexOfLineFromTop);           // Mark line as empty
	
	// Shift all lines above the deleted line downward
	while (indexOfLineFromTop >= 1)
	{
		swapLineBoardAndColor(indexOfLineFromTop, indexOfLineFromTop - 1);
		indexOfLineFromTop--;
	}
}

/**
 * @brief Checks if a horizontal line is completely filled with blocks
 * @param line Zero-based line index from the top of the board
 * @return true if the line is completely filled, false otherwise
 */
bool Board::IsLineFull(int line)
{
	// Check every column in the specified line
	for (int col = 0; col < GameConfig::GAME_WIDTH; col++)
	{
		// If any position is empty (false), the line is not full
		if (this->gameBoard[line][col] == 0)
			return false;
	}
	return true; // All positions are occupied
}

/**
 * @brief Clears all blocks from a line (sets all positions to false/empty)
 * @param indexOfLineFromTop Zero-based line index from the top
 */
void Board::makeLineFalse(int indexOfLineFromTop)
{
	int i = 0;
	for ( i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		this->gameBoard[indexOfLineFromTop][i] = false;
		this->gameBoardColor[indexOfLineFromTop][i] = 0;//BLACK BACKGROUND
	}
}

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
		gotoxy(GameConfig::MIN_X_BOARD_1+i, GameConfig::MIN_Y_BOARD_1 + firstLineFromTop);
		if (this->gameBoard[firstLineFromTop][i] == true)
		{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),GameConfig::COLORS[this->gameBoardColor[firstLineFromTop][i]]); //casting auto for char to int?
			cout << (char)219;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[0]);
			cout << ' ';
		}

			gotoxy(GameConfig::MIN_X_BOARD_1+i, GameConfig::MIN_Y_BOARD_1 + secondLineFromTop);
		if (this->gameBoard[secondLineFromTop][i] == true)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[this->gameBoardColor[secondLineFromTop][i]]);//casting auto for char to int?
			cout << (char)219;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[0]);
			cout << ' ';
		}

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

		if (this->gameBoard[blockY][blockX] == true)
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

		if (this->gameBoard[blockY][blockX] == true)
			return true;
	}
	return false;
}

void Board::printShape(char charOfShape) //Should we remove the shape parameter? WE JUST DIDDDDD
{
	if (charOfShape == ' ')
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),GameConfig::COLORS[0]);
	else
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->currentShape->getColor());
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
	this->shapeIsFalling = true;
}

/**
 * @brief Permanently places the current tetromino onto the game board
 * 
 * This function transfers the current falling tetromino from its temporary
 * falling state to permanent placement on the board. Each block of the 
 * tetromino is marked as occupied in the gameBoard array and its color
 * information is stored in the gameBoardColor array for rendering.
 */
void Board::placeTetromino()
{
	// Place each block of the current tetromino on the board
	for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
	{
		int blockX = this->currentShape->GetBlockX(i);
		int blockY = this->currentShape->GetBlockY(i);
		
		// Mark position as occupied
		this->gameBoard[blockY][blockX] = true;
		
		// Store color information for rendering (shape type + 1 to avoid 0)
		this->gameBoardColor[blockY][blockX] = char(this->currentShape->getType() + 1);
	}
}

void Board::moveCurrentShape(GameConfig::eKeys direction)
{  
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
			this->gameBoardColor[i][j] = 0; //Check if really 0
		}
	}
	delete currentShape;
	shapeIsFalling = false;
}

void Board::printTheBoardFromZero()
{
	//void clrscr();//clean the board
	//drawBorderForBoard() from the TetrisGame so maybe need to move the function for board //print empty board
	for (int i = 0; i < GameConfig::GAME_HEIGHT; i++)
	{
		gotoxy(GameConfig::MIN_X_BOARD_1, GameConfig::MIN_Y_BOARD_1 + i);
		printLineInBoard(i);
	}

}

void Board::printLineInBoard(int line)
{
	for (int i = 0; i < GameConfig::GAME_WIDTH; i++)
	{
		if (this->gameBoard[line][i] == true)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[this->gameBoardColor[line][i]]); //casting auto for char to int?
			cout << (char)219;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GameConfig::COLORS[0]);
			cout << ' ';
		}
	}
}