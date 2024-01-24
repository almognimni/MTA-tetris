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
	Player p2;
	
	enum GameState {
		NEW,
		PLAYING,
		PAUSED,
		POST,
		EXIT
	} currrentState;

public:
	TetrisGame();
	void printLogo();
	void printColoredLogo(); // Used the other one
	void printTetrisAsciiArt();
	void showMenu() ;
	void startGame();
	//void drawBorderForBoard();
	void reset() { p1.reset(), p2.reset(); }
	void showInstructions();
	void postGameScreen();

private:
	void printColoredLine(const std::string& line, const char* color);

};

#endif

