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
	Board myPlayerBoard; // Check how to make private


	Player(short unsigned int ID) : ID(ID), myPlayerBoard(ID), alive(true){};
	Player(const Player& other) = delete;
	bool isAlive() const { return alive; }
	void killPlayer() { this->alive = false; }
	void reset() { myPlayerBoard.reset(); alive = true; };
	void handleInput(char key);
	bool checkIfLost();

};

#endif