#include "TetrisGame.h"

TetrisGame::TetrisGame(): p1(1), p2(2), currrentState(NEW)
{
	srand(time(0));


	while (currrentState != EXIT)
	{
		gotoxy(0, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLACK);
		switch (currrentState)
		{
		case NEW:
			showMenu();
			break;
		case PLAYING:
			startGame();
			break;
		case PAUSED:
			showMenu();
		break;
		case POST:
			postGameScreen();
			break;
		}
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
			if (currrentState == NEW)
		cout << "(3) Toggle colors" << endl;
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
			showInstructions();
			break;
		case EXIT_GAME:
			currrentState = EXIT;
			break;
		case 3:
		if (currrentState == NEW)
		{
			toggleColors();
			valid = true; //To print the menu again with/without colors
			break;
		}
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
	//int indexOfLineFromTop; moved to function
	p1.myPlayerBoard.printBoard();
	p2.myPlayerBoard.printBoard();

	while (p1.isAlive() && p2.isAlive())
	{
		if (p1.myPlayerBoard.isShapeFalling() == false) //If there is no active shape falling, generate
				p1.myPlayerBoard.generateTetromino();

		if (p2.myPlayerBoard.isShapeFalling() == false)
				p2.myPlayerBoard.generateTetromino();

		if (p1.checkIfLost() || p2.checkIfLost())
		{
			currrentState = POST;
			return;
		}

		p1.myPlayerBoard.printShape();
		p2.myPlayerBoard.printShape();

		char keyPressed = 0;

		//fflush(stdin);
		for (int i = 0; i < 10; i++) //input refreshes 10 times before lowering automatically
		{
			if (_kbhit())
			{
				keyPressed = _getch();
				keyPressed = tolower(keyPressed);
				if (keyPressed == (int)GameConfig::eKeys::ESC)
				{
					currrentState = PAUSED;
					return;
				}
				p1.handleInput(keyPressed);
				p2.handleInput(keyPressed);
			}
			Sleep(50);
		}

			p1.myPlayerBoard.moveCurrentShape(GameConfig::eKeys::DROP);
			p2.myPlayerBoard.moveCurrentShape(GameConfig::eKeys::DROP);
		// if the shape is still falling, lower it. else it will be placed and deleted (the deletion is in "placeTetromino" inside moveCurrentShape)
		if (p1.myPlayerBoard.isShapeFalling() == false)
			p1.myPlayerBoard.deleteFullLines();

		if (p2.myPlayerBoard.isShapeFalling() == false)
			p2.myPlayerBoard.deleteFullLines();	//delete full lines if there are any
	}
	currrentState = POST;
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


void TetrisGame::printColoredLine(const std::string& line, const char* color )
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

	const std::string lines[] =
	{
		"TTTTT  EEEEE  TTTTT  RRRR   IIIII   SSSS  ",
		"  T    E        T    R   R    I    S      ",
		"  T    EEE      T    RRRR     I     SSS   ",
		"  T    E        T    R R      I        S  ",
		"  T    EEEEE    T    R  RR  IIIII  SSSS   "
	};

	const char* colors[] =
	{
		"\033[31m", // Red
		"\033[32m", // Green
		"\033[33m", // Yellow
		"\033[34m", // Blue
		"\033[35m", // Magenta
		"\033[36m"  // Cyan
	};

	if (this->p1.myPlayerBoard.isColored() == true)
	{
		for (int i = 0; i < 5; ++i)
		{
			printColoredLine(lines[i].substr(0, 5), colors[0]);  // T - Red
			printColoredLine(lines[i].substr(6, 5), colors[1]);  // E - Green
			printColoredLine(lines[i].substr(13, 5), colors[2]); // T - Yellow
			printColoredLine(lines[i].substr(20, 5), colors[3]); // R - Blue
			printColoredLine(lines[i].substr(27, 5), colors[4]); // I - Magenta
			printColoredLine(lines[i].substr(34, 6), colors[5]); // S - Cyan
			std::cout << std::endl;
		}
	}
	else
	{
		for (int i = 0; i < 5; ++i)
		{
			printColoredLine(lines[i].substr(0, 5));  // T - Red
			printColoredLine(lines[i].substr(6, 5));  // E - Green
			printColoredLine(lines[i].substr(13, 5)); // T - Yellow
			printColoredLine(lines[i].substr(20, 5)); // R - Blue
			printColoredLine(lines[i].substr(27, 5)); // I - Magenta
			printColoredLine(lines[i].substr(34, 6)); // S - Cyan
			std::cout << std::endl;
		}
	}
	cout << border << endl;
	cout << endl;
}

void TetrisGame::showInstructions()
{
	clrscr();
	cout << "Tetris is a tile-matching game where players must arrange falling blocks, called Tetriminos, into complete rows without any gaps." << endl
		<< "When a row is complete, it disappears, and the player earns points." << endl
		<< "The goal is to clear as many rows as possible before the Tetriminos stack up to the top of the playing field." << endl << endl
		<< "Controls:" << endl
		<< "Player:				Player One		Player Two" << endl;

	for (int i = 0; i < 67; i++) //Prints underline
	{
		cout << "-";
	}
	cout << endl;

	cout
		<< "Move Left:			Press A			Press J" << endl

		<< "Move Right:			Press D			Press L" << endl
		<< "Rotate Clockwise:		Press W			Press I" << endl
		<< "Rotate Counterclockwise:	Press S			Press K" << endl
		<< "Move Down:			Press X			Press M" << endl;


	cout << "Press anykey to continue.";
	_getch(); //waits for player input
	return;
}

void TetrisGame::postGameScreen()
{
	short unsigned int winnerID = (p1.isAlive())? 1 : 2;

	gotoxy(0, GameConfig::GAME_HEIGHT + 5);
	cout << "Player " << winnerID << " has won the game!" << endl
		<< "press 1 to play again or any other key to quit to the main menu";

	Sleep(500); // to handle the case that the player was pressing a button when game ends

	reset();
    switch (_getch())
    {
        case '1':
            currrentState = PLAYING;
            break;
		default:
            currrentState = NEW;
            break;
    }
}

void TetrisGame::toggleColors()
{
	if (this->p1.myPlayerBoard.isColored())
	{
		this->p1.myPlayerBoard.setBoardColors(false);
		this->p2.myPlayerBoard.setBoardColors(false);
	}
	else
	{
		this->p1.myPlayerBoard.setBoardColors(true);
		this->p2.myPlayerBoard.setBoardColors(true);
	}
}