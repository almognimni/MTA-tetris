#ifndef __TETRIS_GAME_H
#define __TETRIS_GAME_H

#include "General.h"
#include "Player.h"
#include "Tetrominoes.h"
#include "gameConfig.h"
#include <iostream>
using namespace std;



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
	void showMenu() const; //numOfChoise need to be enum // void showMenu(TetrisChoice& userChoice, bool IsGamePaused) 
	void startGame();

};

#endif

