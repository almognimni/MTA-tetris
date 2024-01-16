#ifndef __BOARD_H
#define __BOARD_H

#include "gameConfig.h"
class Board
{
private:
	//A board that contains truth values in the places/blocks occupied by shapes on the board
	bool gameBoard[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH] = { };



	void makeLineFalse(int numOfLineFromTheBottom);//make the whole line in the board[][] false
	void clearLineChar(int numOfLineFromTheBottom);//make the line empty in the board printing
	void swapLineFalse(int firstLineFromBottom, int secondLineFromBottom); //NEED TO DO
	void swapLineChar(int firstLineFromBottom, int secondLineFromBottom); //NEED TO DO
public:
	Board();
	void deleteLine(int numOfLineFromTheBottom);
	void printBlockInBoard(int x, int y);

};

#endif
