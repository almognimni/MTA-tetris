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
	Player p1;
	//Player p2;
	bool IsGamePaused = false; //start with false

public:
	//TetrisGame() { };
	TetrisGame() : p1() {};
	void printLogo();
	void printColoredLogo(); // Used the other one
	void printTetrisAsciiArt();
	void showMenu() ; //numOfChoise need to be enum // void showMenu(TetrisChoice& userChoice, bool IsGamePaused) 
	void startGame();
	void drawBorderForBoard();

private:
	void printColoredLine(const std::string& line, const char* color);

};

#endif

