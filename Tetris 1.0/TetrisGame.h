/**
 * @file TetrisGame.h
 * @brief Main game controller for the Tetris game application
 * 
 * This file contains the TetrisGame class which manages the overall game state,
 * menu system, game flow, and user interface for a Tetris game implementation.
 * The game supports single-player mode with menu navigation and game state management.
 */

#ifndef __TETRIS_GAME_H
#define __TETRIS_GAME_H

#include "General.h"
#include "Player.h"
#include "Tetrominoes.h"
#include "gameConfig.h"
#include <iostream>
using namespace std;

/** @brief Character code for the block symbol used in the game display */
constexpr int BLOCK = 219;

/**
 * @brief Enumeration for menu choice options
 * 
 * Defines the available menu options that the user can select from the main menu.
 */
enum TetrisChoice {
	START_NEW_GAME = 1,    ///< Start a new game from the beginning
	CONTINUE_GAME = 2,     ///< Continue a paused game
	//INSTRUCTIONS = 8,    ///< Show game instructions (currently disabled)
	EXIT_GAME = 9          ///< Exit the application
};


/**
 * @brief Main game controller class for the Tetris game
 * 
 * The TetrisGame class manages the overall game state, handles the menu system,
 * controls game flow, and provides the main game loop. It coordinates between
 * different game states such as menu, playing, and paused states.
 */
class TetrisGame
{
	Player p1;              ///< Player 1 object (currently only single-player supported)
	//Player p2;            ///< Player 2 object (reserved for future multiplayer support)
	
	/**
	 * @brief Enumeration for different game states
	 * 
	 * Defines the various states the game can be in during execution.
	 */
	enum GameState {
		MENU,                ///< Main menu state
		NEW = 1,            ///< New game state (currently unused)
		PLAYING,            ///< Active gameplay state
		PAUSED,             ///< Game paused state
		POST,               ///< Post-game state (reserved for future use)
		INSTRUCTIONS = 8,   ///< Instructions display state
		EXIT = 9            ///< Exit application state
	} currrentState;        ///< Current state of the game

public:
	/**
	 * @brief Constructor that initializes and runs the main game loop
	 * 
	 * Initializes the game state, sets up random seed, and enters the main
	 * game loop that handles state transitions between menu, gameplay, and other states.
	 */
	TetrisGame();
	
	/**
	 * @brief Prints a simple text logo (currently unused)
	 */
	void printLogo();
	
	/**
	 * @brief Prints a colored ASCII art logo (alternative to printLogo)
	 */
	void printColoredLogo();
	
	/**
	 * @brief Prints ASCII art for the Tetris game title
	 */
	void printTetrisAsciiArt();
	
	/**
	 * @brief Displays the main menu and handles user input
	 * 
	 * Shows menu options and processes user selection to change game state.
	 */
	void showMenu();
	
	/**
	 * @brief Starts and manages the main gameplay loop
	 * 
	 * Handles the core game mechanics, input processing, and game board updates
	 * during active gameplay.
	 */
	void startGame();
	
	/**
	 * @brief Draws the border around the game board
	 * 
	 * Renders the visual border that surrounds the Tetris playing field.
	 */
	void drawBorderForBoard();
	
	/**
	 * @brief Resets the game to initial state
	 * 
	 * Resets player state and prepares for a new game session.
	 */
	void reset() { p1.reset(); } // TODO: add p2.reset() for multiplayer
	
	/**
	 * @brief Shows game instructions to the player
	 */
	void showInstructions();

private:
	/**
	 * @brief Helper function to print colored text lines
	 * @param line The text line to print
	 * @param color The ANSI color code to use
	 */
	void printColoredLine(const std::string& line, const char* color);

};

#endif

