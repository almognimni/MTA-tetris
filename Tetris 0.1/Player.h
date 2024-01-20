#ifndef __PLAYER_H
#define __PLAYER_H

#include "Board.h"
#include "Tetrominoes.h"

class Player
{
private:
	bool alive;
	Tetrominoes currentTetromino;

public:
	Player() : myPlayerBoard(), alive(true){}; // ��� �� ���� ��� ����� �� ���� ������ ����� ������
	Player(const Player& other) = delete; // What is this?
	bool isAlive() const { return alive; }
	void generateTetromino();


	Board myPlayerBoard; // Check how to make private
};

#endif