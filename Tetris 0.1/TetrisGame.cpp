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
	cout << "Tetris" << "\n" << "Welcome to the Tetris game" << endl;
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
		clrscr(); //make empty screen
		gotoxy(0, 0);
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
	drawBorderForBoard(); //Need to draw for both players
	p1.myPlayerBoard.printShape(p1.myPlayerBoard.currentShape, (char)BLOCK);//print
	bool IsGameStillOn = true;
	while (IsGameStillOn)
	{
		int keyPressed = 0;
		if (_kbhit())
		{
			keyPressed = _getch();
			if (keyPressed == (int)GameConfig::eKeys::ESC)
				break;
		}
	//	s.move((GameConfig::eKeys)keyPressed);
		p1.myPlayerBoard.printShape(p1.myPlayerBoard.currentShape, ' ');//clean
			p1.myPlayerBoard.currentShape.lower();

		p1.myPlayerBoard.printShape(p1.myPlayerBoard.currentShape, (char)BLOCK);//print

			Sleep(500);
		


		
	}
	
		

	
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