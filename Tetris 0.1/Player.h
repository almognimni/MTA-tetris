#ifndef __PLAYER_H
#define __PLAYER_H

#include "Board.h"
class Player
{
private:
	Board myPlayerBoard;
	bool isAlive;

public:
	Player() : myPlayerBoard(), isAlive(true){}; // ��� �� ���� ��� ����� �� ���� ������ ����� ������
	Player(const Player& other) = delete;
	
};

#endif