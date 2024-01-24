#include "Block.h"

Block::Block() {
	this->x = 0;
	this->y = 0;
}

Block::Block(int x,int y) {
	this->x = x;
	this->y = y;
}

int Block::getX() const { return this->x; }
int Block::getY() const { return this->y; }

void Block::lower()
{
	this->y++;
}

void Block::moveRight()
{
	this->x++;
}

void Block::moveLeft()
{
	this->x--;
}