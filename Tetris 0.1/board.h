#ifndef __BOARD_H
#define __BOARD_H

#include "gameConfig.h"
#include "Tetrominoes.h"
#include "General.h"
#include <iostream> 

class Board
{
public:
     
    int printLocation;  // X-coordinate for printing on the screen
	bool gameBoard[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH];  //A board that contains truth values in the blocks occupied by tetrominoes on the board
    Tetrominoes* currentTetromino;// Pointer to the current falling tetromino
    char gameBoardColor[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH] = {}; // 2D array to represent the color of each block , Initialized to default color 


private:

    short unsigned int ID; // Player ID
    bool tetrominoIsFalling; // Flag indicating if a tetromino is currently falling
    bool gameWithColors; // Flag indicating if the game uses colors

private:

    void makeLineFalse(int indexOfLineFromTop);//make the whole line in the board[][] false
	
    void clearLineChar(int indexOfLineFromTop);//make the line empty in the board printing
	
    void swapLineBoardAndColor(int firstLineFromTop, int secondLineFromTOP);    // Swap the content of two lines on the board (both blocks and colors)
	
    void printTheSwap(int firstLineFromTop, int secondLineFromTOP);      // Print the swap effect when swapping two lines on the board
	
    void deleteLine(int indexOfLineFromTop);    // Delete a line on the board by moving all lines above it down
     
    void placeTetromino();    // Place the current falling tetromino on the board
   
    void printLineInBoard(int line);     // Print a line on the game board
	
    void printBlockInBoard(Block curBlock);    // Print a single block of a tetromino on the board

    void printBoardBoarders();     // Print the borders of the game board


public:

    bool IsLineFull(int line);    // Check if a specific line on the board is full

    Board(short unsigned int ID) : ID(ID), gameBoard(), currentTetromino(nullptr), tetrominoIsFalling(false) { printLocation = (ID == 1) ? GameConfig::MIN_X_BOARD_1 : GameConfig::MIN_X_BOARD_2; };     // Constructor for the Board class

    Board(const Board& b) = delete;

    void generateTetromino();     // Generate a new falling tetromino

    bool GetGameBoardValue(int x, int y) const;     // Get the truth value of a specific block on the game board

    bool isOverlapping() const;     // Check if the current falling tetromino is overlapping with any occupied blocks on the board

	bool isOverlapping(GameConfig::eKeys direction) const;     // Check if moving in a specific direction would cause the tetromino to overlap with occupied blocks

    void printTetromino(char charOfTetromino = GameConfig::BLOCK);    // Print the current falling tetromino on the board with a specified character (default is a block character)

    void moveCurrentTetromino(GameConfig::eKeys);       // Moves the current tetromino in the specified direction. If the tetromino has reached a stop, places it on the board
   
    bool isTetrominoFalling() { return tetrominoIsFalling; }     // Check if a tetromino is currently falling

    void reset();    // Reset the game board and other parameters

    void printBoard();    // Print the entire game board

    void deleteFullLines();     // Delete any full lines on the game board and shift blocks down

    bool isColored() const { return gameWithColors; }     // Check if the game is using colored blocks

    void setBoardColors(bool input) { this->gameWithColors = input; }     // Set the flag for using colored blocks





};

#endif