#ifndef __PLAYER_H
#define __PLAYER_H

#include "Board.h"
#include "Tetrominoes.h"

class Player
{
private:
	bool alive;
	//Tetrominoes currentTetromino;
public:
	Board myPlayerBoard; // Check how to make private


	Player() : myPlayerBoard(), alive(true){}; // אני לא בטוח איך לבנות את הלוח מבחינת הקצאה וכדומה
	Player(const Player& other) = delete; // What is this?
	bool isAlive() const { return alive; }
	void killPlayer() { this->alive = false; }


};

#endif