#ifndef __TETRIS_GAME_H
#define __TETRIS_GAME_H

#include "General.h"
#include "Player.h"
#include "Tetrominoes.h"
#include "gameConfig.h"
#include <iostream>
using namespace std;

constexpr int BLOCK = 219;

enum TetrisChoice {
	START_NEW_GAME = 1,
	CONTINUE_GAME = 2,
	//INSTRUCTIONS = 8,
	EXIT_GAME = 9
};


class TetrisGame
{
	Player p1;
	//Player p2;
	//bool IsGamePaused = false; //start with false // Might be replaced by GameState
	
	enum GameState {
		MENU,
		NEW = 1,
		PLAYING,
		PAUSED,
		POST,
		INSTRUCTIONS = 8,
		EXIT = 9
	} currrentState;

public:
	TetrisGame();
	void printLogo();
	void printColoredLogo(); // Used the other one
	void printTetrisAsciiArt();
	void showMenu() ; //numOfChoise need to be enum // void showMenu(TetrisChoice& userChoice, bool IsGamePaused) 
	void startGame();
	void drawBorderForBoard();
	void reset() { p1.reset(); } //add p2(reset)
	void showInstructions();

private:
	void printColoredLine(const std::string& line, const char* color);

};

#endif

