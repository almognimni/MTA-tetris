/**
 * @file board.h
 * @brief Game board management for Tetris gameplay
 * 
 * This file contains the Board class which manages the Tetris playing field,
 * including piece placement, line detection and clearing, collision detection,
 * and board rendering. The board maintains the state of all placed pieces
 * and coordinates with falling tetrominoes.
 */

#ifndef __BOARD_H
#define __BOARD_H

#include "gameConfig.h"
#include "Tetrominoes.h"
#include "General.h"
#include <iostream> 

/**
 * @brief Game board class that manages the Tetris playing field
 * 
 * The Board class handles all aspects of the Tetris playing field including:
 * - Tracking placed pieces and their colors
 * - Managing the currently falling tetromino
 * - Collision detection for movement and rotation
 * - Line completion detection and clearing
 * - Board rendering and visual updates
 */
class Board
{
public:
	/** @brief 2D array representing occupied positions on the board */
	bool gameBoard[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH];
	
	/** @brief Pointer to the currently falling tetromino piece */
	Tetrominoes* currentShape;
	
	/** @brief 2D array storing color information for each board position */
	char gameBoardColor[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH] = {};

private:
	/** @brief Flag indicating whether a shape is currently falling */
	bool shapeIsFalling;
    
	/**
	 * @brief Sets all positions in a line to false (empty)
	 * @param indexOfLineFromTop Line index from top of board (0-based)
	 */
	void makeLineFalse(int indexOfLineFromTop);
	
	/**
	 * @brief Clears the visual representation of a line on screen
	 * @param indexOfLineFromTop Line index from top of board (0-based)
	 */
	void clearLineChar(int indexOfLineFromTop);
	
	/**
	 * @brief Swaps the content of two lines on the board
	 * @param firstLineFromTop Index of first line from top
	 * @param secondLineFromTOP Index of second line from top
	 */
	void swapLineBoardAndColor(int firstLineFromTop, int secondLineFromTOP);
	
	/**
	 * @brief Prints the visual swap of two lines (for animation)
	 * @param firstLineFromTop Index of first line from top
	 * @param secondLineFromTOP Index of second line from top
	 */
	void printTheSwap(int firstLineFromTop, int secondLineFromTOP);

public:
	/**
	 * @brief Default constructor - initializes empty board
	 */
	Board() : gameBoard(), currentShape(nullptr), shapeIsFalling(false) {};
	
	//~Board(); // Destructor not explicitly needed
	
	/**
	 * @brief Deletes a completed line and shifts lines above it down
	 * @param indexOfLineFromTop Line index from top of board to delete
	 */
	void deleteLine(int indexOfLineFromTop);
	
	/**
	 * @brief Prints a single block at its position on the board
	 * @param curBlock Block object to print
	 */
	void printBlockInBoard(Block curBlock);
	
	/**
	 * @brief Gets the occupied state of a specific board position
	 * @param x X coordinate (column)
	 * @param y Y coordinate (row)
	 * @return true if position is occupied, false if empty
	 */
	bool GetGameBoardValue(int x, int y) const;
	
	/**
	 * @brief Checks if a line is completely filled with pieces
	 * @param line Line index from top to check
	 * @return true if line is full, false otherwise
	 */
	bool IsLineFull(int line);
	
	/**
	 * @brief Generates a new random tetromino piece
	 */
	void generateTetromino();
	
	/**
	 * @brief Destroys the current tetromino and frees its memory
	 */
	void destroyTetromino();
	
	/**
	 * @brief Checks if current tetromino overlaps with placed pieces
	 * @return true if overlapping (game over condition), false otherwise
	 */
	bool isOverlapping() const;
	
	/**
	 * @brief Checks if movement in a direction would cause overlap
	 * @param direction Direction to check for potential movement
	 * @return true if direction is blocked, false if movement is valid
	 */
	bool isOverlapping(GameConfig::eKeys direction) const;
	
	/**
	 * @brief Places the current tetromino permanently on the board
	 */
	void placeTetromino();
	
	/**
	 * @brief Prints the current shape at its position
	 * @param charOfShape Character to use for drawing the shape
	 */
	void printShape(char charOfShape);
	
	/**
	 * @brief Moves the current shape in the specified direction
	 * @param direction Direction key for movement
	 * @return true if shape was placed (hit bottom), false if still falling
	 */
	bool moveCurrentShape(GameConfig::eKeys direction);

	/**
	 * @brief Checks if a shape is currently falling
	 * @return true if shape is falling, false otherwise
	 */
	bool isShapeFalling() { return shapeIsFalling; }

	/**
	 * @brief Resets the board to initial empty state
	 */
	void reset();

	/**
	 * @brief Prints the entire board from top to bottom
	 */
	void printTheBoardFromZero();
	
	/**
	 * @brief Prints a specific line of the board
	 * @param line Line index to print
	 */
	void printLineInBoard(int line);

};

#endif