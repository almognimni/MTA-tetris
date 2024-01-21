#ifndef __BOARD_H
#define __BOARD_H

#include "gameConfig.h"
#include "Tetrominoes.h"
#include "General.h"
#include <iostream> 

class Board
{
public:
	//A board that contains truth values in the places/blocks occupied by shapes on the board
	bool gameBoard[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH];
    Tetrominoes currentShape;
private:



	void makeLineFalse(int numOfLineFromTheBottom);//make the whole line in the board[][] false
	void clearLineChar(int numOfLineFromTheBottom);//make the line empty in the board printing
	void swapLineFalse(int firstLineFromBottom, int secondLineFromBottom); //NEED TO DO
	void swapLineChar(int firstLineFromBottom, int secondLineFromBottom); //NEED TO DO
public:
    Board() : currentShape() , gameBoard() {};
	void deleteLine(int numOfLineFromTheBottom);
	void printBlockInBoard(Block curBlock);
    bool GetGameBoardValue(int x, int y) const; //19/01/24

    void generateTetromino();
	bool isOverlapping(const Tetrominoes& tetromino) const;
	bool isPlaced(const Tetrominoes tetromino);
    void placeTetromino();
    void printShape(const Tetrominoes& tetromino, char charOfShape) ;

};

#endif

/*
Example for colition check by the board (will need to first make get functions to get cordinates to check from):

bool Board::isOverlapping(const Tetromino& tetromino)
{
    for (const Block& block : tetromino.blocks)
    {
        if (block.x < 0 || block.x >= BOARD_SIZE || block.y < 0 || block.y >= BOARD_SIZE)
        {
            // Out of bounds
            return true;
        }
        if (gameBoard[block.x][block.y])
        {
            // Position on the board is occupied
            return true;
        }
    }
    // No overlaps found
    return false;

*/