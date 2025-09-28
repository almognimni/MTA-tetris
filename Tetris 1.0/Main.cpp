
/**
 * @file Main.cpp
 * @brief Entry point for the Tetris game application
 * 
 * This file contains the main function that initializes and starts
 * the Tetris game. It sets up the console environment and creates
 * the main game controller.
 */

#include "TetrisGame.h"

/**
 * @brief Main entry point of the Tetris game application
 * 
 * Initializes the console environment and creates a TetrisGame instance
 * which handles all game logic, menu systems, and user interaction.
 * The game runs until the user chooses to exit.
 * 
 * @return 0 on successful program completion
 */
int main()
{
	maximizeConsole(); // Attempt to maximize console window (currently not working)

	// Create and run the main game controller
	TetrisGame Game;
	
	// Position cursor below the game area for any final output
	gotoxy(0, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y_BOARD_1 + 2);
	return 0;
}