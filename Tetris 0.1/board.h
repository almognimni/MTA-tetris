#ifndef __BOARD_H
#define __BOARD_H

#include "gameConfig.h"
#include "Tetrominoes.h"
#include "General.h"
#include <iostream> 

class Board
{
public:

    int printLocation;
	//A board that contains truth values in the places/blocks occupied by shapes on the board
	bool gameBoard[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH];
    Tetrominoes* currentShape;
    char gameBoardColor[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH] = {};


private:

    short unsigned int ID;
    bool shapeIsFalling;

private:
	void makeLineFalse(int indexOfLineFromTop);//make the whole line in the board[][] false
	void clearLineChar(int indexOfLineFromTop);//make the line empty in the board printing
	void swapLineBoardAndColor(int firstLineFromTop, int secondLineFromTOP);
	void printTheSwap(int firstLineFromTop, int secondLineFromTOP); 
	void deleteLine(int indexOfLineFromTop);
    void destroyTetromino();
    void placeTetromino();
    void printLineInBoard(int line);
	void printBlockInBoard(Block curBlock);
    void printBoardBoarders();
    bool gameWithColors;

public:
    bool IsLineFull(int line);
    Board(short unsigned int ID) : ID(ID), gameBoard(), currentShape(nullptr), shapeIsFalling(false) { printLocation = (ID == 1) ? GameConfig::MIN_X_BOARD_1 : GameConfig::MIN_X_BOARD_2; };
    void generateTetromino();
    bool GetGameBoardValue(int x, int y) const; //19/01/24
    bool isOverlapping() const; //Checks if the current position is occupied (For game end)
	bool isOverlapping(GameConfig::eKeys direction) const; //Checks if a certain direction is occupied
    void printShape(char charOfShape = GameConfig::BLOCK);
    void moveCurrentShape(GameConfig::eKeys); //Returns true if shape has been placed
    bool isShapeFalling() { return shapeIsFalling; }
    void reset();
    void printBoard();
    void deleteFullLines();
    bool isColored() const { return gameWithColors; }
    void setBoardColors(bool input) { this->gameWithColors = input; }




};

#endif