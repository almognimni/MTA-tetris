/**
 * @file Player.h
 * @brief Player representation and game state management
 * 
 * This file contains the Player class which represents a game player,
 * managing their board state, life status, and providing reset functionality.
 * Currently supports single-player mode with provisions for future multiplayer.
 */

#ifndef __PLAYER_H
#define __PLAYER_H

#include "Board.h"
#include "Tetrominoes.h"

/**
 * @brief Player class representing a game participant
 * 
 * The Player class encapsulates all player-specific game state including
 * their individual game board, life status, and game progression. Each
 * player manages their own board and tetromino pieces independently.
 */
class Player
{
private:
	/** @brief Flag indicating if the player is still alive (not game over) */
	bool alive;
	//Tetrominoes currentTetromino; // Moved to Board class for better management
	
public:
	/** @brief The player's individual game board */
	Board myPlayerBoard; // TODO: Consider making this private for better encapsulation

	/**
	 * @brief Default constructor - initializes player with empty board
	 */
	Player() : myPlayerBoard(), alive(true){};
	
	/**
	 * @brief Copy constructor is explicitly deleted
	 * 
	 * Players should not be copied to avoid issues with board state
	 * and memory management of tetromino pieces.
	 */
	Player(const Player& other) = delete;
	
	/**
	 * @brief Checks if the player is still alive (game not over)
	 * @return true if player is alive, false if game over
	 */
	bool isAlive() const { return alive; }
	
	/**
	 * @brief Ends the game for this player (sets game over state)
	 */
	void killPlayer() { this->alive = false; }
	
	/**
	 * @brief Resets player to initial state for a new game
	 * 
	 * Clears the board and restores the player to alive status,
	 * ready for a fresh game session.
	 */
	void reset() { myPlayerBoard.reset(); alive = true; };

};

#endif