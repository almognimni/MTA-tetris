#include "TetrisGame.h"

const int BLOCK = 219;
const int SPACE = ' ';

void TetrisGame::drawBorderForBoard()
{
	for (int col = GameConfig::MIN_X_BOARD_1; col <= GameConfig::GAME_WIDTH + GameConfig::MIN_X_BOARD_1; col++)
	{
		gotoxy(col, GameConfig::MIN_Y_BOARD_1 - 1);
		cout << "-";

		gotoxy(col, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y_BOARD_1);
		cout << "-";
	}

	for (int row = GameConfig::MIN_Y_BOARD_1 - 1; row <= GameConfig::GAME_HEIGHT + GameConfig::MIN_Y_BOARD_1; row++)
	{
		gotoxy(GameConfig::MIN_X_BOARD_1 - 1, row);
		cout << "|";

		gotoxy(GameConfig::GAME_WIDTH + GameConfig::MIN_X_BOARD_1, row);
		cout << "|";
	}

}
void TetrisGame::showMenu() 
{
	int userChoice;
	//cout << "Tetris" << "\n" << endl; // << "Welcome to the Tetris game";
	cout << "Menu:" << endl;
	cout << "(1) Start a new game" << endl;
	if (IsGamePaused == true)
		cout << "(2) Continue a paused game" << endl;
	cout << "(8) Present instructions and keys" << endl;
	cout << "(9) EXIT" << endl;



	//bool IsVaildChoice = false;
	//	while(IsVaildChoice!=true)
		//{
	cout << "Enter your choice: ";
	cin >> userChoice;

	switch (userChoice) {
	case START_NEW_GAME:
		// Handle starting a new game
		gotoxy(0, 0);
		clrscr(); //make empty screen
		startGame();
		break;
	case CONTINUE_GAME:
		//if(isGamePaused==false) need to write wrong message for this case
		// Handle continuing a paused game
		break;
	case INSTRUCTIONS:
		// Handle displaying instructions
		break;
	case EXIT_GAME:
		// Handle exiting the game
		break;
	default:
		//	IsVaildChoice=true;
			// Handle invalid choice
		break;
	}
	gotoxy(0, 0);
}

/*
void TetrisGame::startGame()
{
	clrscr(); //make empty screen
	drawBorderForBoard();
//	Player p1;
	bool IsGameStillOn = true;
	//Tetrominoes t;
	//while (IsGameStillOn)
	//{
	//	while (t.IsShapeTouchDown == false)
		//{}
	//}

	//Player p2;
}
*/

void TetrisGame::startGame()
{
	gotoxy(0, 0);
	int indexOfLineFromTop;
	bool isGameStillOn = true;
	drawBorderForBoard(); //Need to draw for both players
	while (p1.isAlive()) //Add p2
	{
		p1.myPlayerBoard.generateTetromino();
		if (p1.myPlayerBoard.isOverlapping() == true)
		{
			//p1.setAlive();
		}
		p1.myPlayerBoard.printShape((char)BLOCK);
	bool isFalling = true; //Can be in a class? /Moved down to be reseted/
		//need to reset is falling and call for another shape (currently done before loop)
		int keyPressed = 0;
		while (isFalling)
		{ 
			//input refreshes 10 times before lowering automatically
			for (int i = 0; i < 10; i++)
			{
				fflush(stdin);
				if (_kbhit())
				{
					keyPressed = _getch();
					if (keyPressed == (int)GameConfig::eKeys::ESC)
						break; //Enter menu

					isFalling = p1.myPlayerBoard.moveCurrentShape((GameConfig::eKeys)keyPressed);
				}
					Sleep(50);
			}

			if (isFalling == false) // if the shape has reached the ground, don't lower automatically
				break;

			isFalling = p1.myPlayerBoard.moveCurrentShape(GameConfig::eKeys::DROP);
		}
			//The temp shape has been placed, now may be deleted
			if (p1.myPlayerBoard.currentShape != NULL)
				delete p1.myPlayerBoard.currentShape;

		//for checking if need do delete line
			indexOfLineFromTop = GameConfig::GAME_HEIGHT - 1;
			while (indexOfLineFromTop >=0)
			{
				if (p1.myPlayerBoard.IsLineFull(indexOfLineFromTop) == true)
				{
					p1.myPlayerBoard.deleteLine(indexOfLineFromTop);
				}
				else
				indexOfLineFromTop--;
			}


	//	s.move((GameConfig::eKeys)keyPressed);


		/*
		p1.myPlayerBoard.printShape(p1.myPlayerBoard.currentShape, ' ');//clean
			p1.myPlayerBoard.currentShape.lower();

		p1.myPlayerBoard.printShape(p1.myPlayerBoard.currentShape, (char)BLOCK);//print

			Sleep(500); sleep(currentSpeed)
		*/


		
	}
	
		

	
}

void TetrisGame::printLogo()
{
	const char* lines[] = {
		"TTTTT  EEEEE  TTTTT  RRRR   IIIII   SSSS  ",
		"  T    E        T    R   R    I    S      ",
		"  T    EEE      T    RRRR     I     SSS   ",
		"  T    E        T    R R      I        S  ",
		"  T    EEEEE    T    R  RR  IIIII  SSSS   "
	};

	std::string border(40, '*');

	cout << border << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << lines[i] << endl;
	}
	cout << border << endl;
	cout << endl;
}

/*
while (true)
	{
		int keyPressed = 0;
		if (_kbhit())
		{
			keyPressed = _getch();
			if (keyPressed == (int)GameConfig::eKeys::ESC)
				break;
		}
		s.move((GameConfig::eKeys)keyPressed);
		Sleep(500);
	}



*/


