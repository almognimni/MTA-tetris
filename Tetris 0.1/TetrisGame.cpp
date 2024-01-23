#include "TetrisGame.h"

TetrisGame::TetrisGame(): p1(), currrentState(MENU)
{
	srand(time(0));


	while (currrentState != EXIT)
	{
		gotoxy(0, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLACK);
		switch (currrentState)
		{
		case MENU:
			showMenu();
			break;
		//case NEW:
			//reset();
			//currrentState = PLAYING;
		case PLAYING:
			startGame();
			break;
		case PAUSED:
			showMenu();
		break;
		//case INSTRUCTIONS:
		//showInstructions()
		//break;
		}
	}
}

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
	clrscr();
	printTetrisAsciiArt();
	int userChoice;
	bool valid;

	cout << "Menu:" << endl;
	do
	{
		valid = true;
		cout << "(1) Start a new game" << endl;
		if (currrentState == PAUSED)
			cout << "(2) Continue a paused game" << endl;
		cout << "(8) Present instructions and keys" << endl;
		cout << "(9) EXIT" << endl;

		cout << "Enter your choice: ";
		cin >> userChoice;

		switch (userChoice)
		{
		case START_NEW_GAME:
			// Handle starting a new game
			if (currrentState == PAUSED)
				reset();
			currrentState = PLAYING;
			break;

		case CONTINUE_GAME:
			if (currrentState == PAUSED)
				startGame();
			else
				valid = false;
			break;
		case INSTRUCTIONS:
			currrentState = INSTRUCTIONS;
			// Handle displaying instructions
			break;
		case EXIT_GAME:
			currrentState = EXIT;
			break;
		default:
			valid = false;
			break;
		}
		if (!valid)
			cout << "Invalid choice" << endl;
	} while (!valid);
}

void TetrisGame::startGame()
{
	clrscr();
	gotoxy(0, 0);
	int indexOfLineFromTop;
	drawBorderForBoard(); //Need to draw for both players
	//printPlayerBoard(p1, p2); // 
	p1.myPlayerBoard.printTheBoardFromZero();

	while (p1.isAlive()) //Add p2
	{
		//if (p1.myPlayerBoard.currentShape == NULL) // If resuming a paused game, no need to generate shape
			if (p1.myPlayerBoard.isShapeFalling() == false) //If there is no active shape falling, generate
			p1.myPlayerBoard.generateTetromino();

		if (p1.myPlayerBoard.isOverlapping() == true) //If the generated shape is overlapping - player lost
		{
			p1.killPlayer();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLACK); //reset the color before printing text
			cout << "Player 1 has lost the game" << endl;
			currrentState = POST; // will have a screen saying who won, score, and ability to play again
			return;
		}


		p1.myPlayerBoard.printShape((char)BLOCK);

		int keyPressed = 0;
		while (p1.myPlayerBoard.isShapeFalling() == true)
		{

			
			fflush(stdin);
			for (int i = 0; i < 10; i++) //input refreshes 10 times before lowering automatically
			{
				if (_kbhit())
				{
					keyPressed = _getch();
					if (keyPressed == (int)GameConfig::eKeys::ESC)
					{
						currrentState = PAUSED;
						return;
					}

					p1.myPlayerBoard.moveCurrentShape((GameConfig::eKeys)keyPressed);
				}
				Sleep(50);
			}

			if (p1.myPlayerBoard.isShapeFalling() == true)// if the shape has reached the ground, don't lower automatically
				p1.myPlayerBoard.moveCurrentShape(GameConfig::eKeys::DROP);

			//Same for 2nd player

		} //ShapeIsFalling = false:
		//The temp shape has been placed, now may be deleted
		if (p1.myPlayerBoard.currentShape != NULL)
			delete p1.myPlayerBoard.currentShape;

		//for checking if need do delete line
		indexOfLineFromTop = GameConfig::GAME_HEIGHT - 1;
		while (indexOfLineFromTop >= 0)
		{
			if (p1.myPlayerBoard.IsLineFull(indexOfLineFromTop) == true)
			{
				p1.myPlayerBoard.deleteLine(indexOfLineFromTop);
			}
			else
				indexOfLineFromTop--;
		}
	}
}

// not used
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

const char* RESET = "\033[0m";
const char* COLORS[] = {
	"\033[31m", // Red
	"\033[32m", // Green
	"\033[33m", // Yellow
	"\033[34m", // Blue
	"\033[35m", // Magenta
	"\033[36m"  // Cyan
};

// not used
void TetrisGame::printColoredLogo() 
{
	const char* lines[] = {
	"TTTTT  EEEEE  TTTTT  RRRR   IIIII   SSSS  ",
	"  T    E        T    R   R    I    S      ",
	"  T    EEE      T    RRRR     I     SSS   ",
	"  T    E        T    R R      I        S  ",
	"  T    EEEEE    T    R  RR  IIIII  SSSS   "
	};

	for (int i = 0; i < 5; ++i) {
		for (int j = 0, colorIndex = 0; lines[i][j] != '\0'; ++j, ++colorIndex) {
			if (lines[i][j] == ' ') {
				std::cout << lines[i][j];
				continue; // Skip spaces
			}
			if (colorIndex >= sizeof(COLORS) / sizeof(COLORS[0])) {
				colorIndex = 0; // Reset color index if it exceeds number of colors
			}
			std::cout << COLORS[colorIndex] << lines[i][j] << RESET;
		}
		std::cout << std::endl;
	}
}

void TetrisGame::printColoredLine(const std::string& line, const char* color)
{
	std::cout << color;
	for (char ch : line) {
		std::cout << ch;
	}
	std::cout << "\033[0m";  // Reset to default color
}

void TetrisGame::printTetrisAsciiArt()
{
	std::cout << "\033[0m";  // Reset to default color

	std::string border(33, '*');

	cout << border << endl;

	const std::string lines[] = {
		"TTTTT  EEEEE  TTTTT  RRRR   IIIII   SSSS  ",
		"  T    E        T    R   R    I    S      ",
		"  T    EEE      T    RRRR     I     SSS   ",
		"  T    E        T    R R      I        S  ",
		"  T    EEEEE    T    R  RR  IIIII  SSSS   "
	};

	const char* colors[] = {
		"\033[31m", // Red
		"\033[32m", // Green
		"\033[33m", // Yellow
		"\033[34m", // Blue
		"\033[35m", // Magenta
		"\033[36m"  // Cyan
	};

	for (int i = 0; i < 5; ++i) {
		printColoredLine(lines[i].substr(0, 5), colors[0]);  // T - Red
		printColoredLine(lines[i].substr(6, 5), colors[1]);  // E - Green
		printColoredLine(lines[i].substr(13, 5), colors[2]); // T - Yellow
		printColoredLine(lines[i].substr(20, 5), colors[3]); // R - Blue
		printColoredLine(lines[i].substr(27, 5), colors[4]); // I - Magenta
		printColoredLine(lines[i].substr(34, 6), colors[5]); // S - Cyan
		std::cout << std::endl;
	}

	cout << border << endl;
	cout << endl;
}


