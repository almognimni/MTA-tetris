#ifndef __PLAYER_H
#define __PLAYER_H

#include "Board.h"
#include "Tetrominoes.h"

class Player
{
private:
	bool alive;
	short unsigned int ID;

public:
	Board myPlayerBoard;


	Player(short unsigned int ID) : ID(ID), myPlayerBoard(ID), alive(true){}; // Constructor for the Player class

	Player(const Player& other) = delete; // Copy constructor is deleted to avoid unintended object copies

	bool isAlive() const { return alive; } // Checks if the player is alive

	void killPlayer() { this->alive = false; } // Sets the player as not alive

	void reset() { myPlayerBoard.reset(); alive = true; }; // Resets the player Game, making the board empty and setting them as alive

	void handleInput(char key);  // Handles receiving input for moving a tetromino to the player
	
	bool checkIfLost(); // Checks if the player has lost the game

};

#endif