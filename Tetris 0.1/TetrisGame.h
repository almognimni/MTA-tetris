#ifndef __TETRIS_GAME_H
#define __TETRIS_GAME_H

#include "Player.h"
#include "Tetrominoes.h"

enum TetrisChoice {
	START_NEW_GAME = 1,
	CONTINUE_GAME = 2,
	INSTRUCTIONS = 8,
	EXIT_GAME = 9
};

class TetrisGame
{
	//Player p1;
	//Player p2;

	bool IsGamePaused = false; //start with false
	
public:
	static void drawBorderForBoard();
	void showMenu() //numOfChoise need to be enum // void showMenu(TetrisChoice& userChoice, bool IsGamePaused) {

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
	//}
	//}
	void startGame()
	{
		clrscr(); //make empty screen
		drawBorderForBoard();
	Player p1;
	bool IsGameStillOn = true;
	//Tetrominoes t;
	while (IsGameStillOn)
	{
		while (t.IsShapeTouchDown == false)
		{


		}


	}

	//Player p2;


	}
}
;
#endif

