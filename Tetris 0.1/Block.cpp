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
	/*
	if (Block::isTouching(0, RIGHT_BORDER))
	{
		return;
	}
	if (Block::isTouching(otherBlock(?))
	{
		return;
	}
	*/

	this->x++;
}

void Block::moveLeft()
{
	/*
	if (Block::isTouching(0, RIGHT_BORDER))
	{
		return;
	}
	if (Block::isTouching(otherBlock(?))
	{
		return;
	}
	*/

	this->x--;
}


/*
Block::Block(const Block& other) {
    this->x = other.x;
    this->y = other.y;
}


bool Block::isTouching(int _x, int _y)
{
	if (this->x - 1 == _x)
		return true;
	if (this->x + 1 == _x)
		return true;
	if (this->y - 1 == _y)
		return true;
	if (this->y + 1 == _y)
		return true;
	return false;
}

bool Block::isTouching(Block& other)
{
	if (this->x - 1 == other.x)
		return true;
	if (this->x + 1 == other.x)
		return true;
	if (this->y - 1 == other.y)
		return true;
	if (this->y + 1 == other.y)
		return true;
	return false;
}

bool Block::isOverlapping(int _x, int _y)
{
	return (this->x == _x && this->y == _y);
}

bool Block::isOverlapping(Block& other)
{
	return (this->x == other.x && this->y == other.y);
}

bool Block::isOverlapping(&Board::gameBoard board)
{
    if (this->x < 0 || this->x >= board.size() || this->y < 0 || this->y >= board[0].size())
    {
        // Out of bounds
        return true;
    }
    return board[this->x][this->y];
}


*/