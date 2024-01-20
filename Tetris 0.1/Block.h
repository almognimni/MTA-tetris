#ifndef __BLOCK_H
#define __BLOCK_H

class Board;

class Block {
    int x;
    int y;

public:
    Block();
    Block(int x, int y);
    void lower();
    void moveRight();
    void moveLeft();
    int getX() const;
    int getY() const;

};

#endif

//The collition checks will be done by the board

/*
Function graveyard
    Block(const Block& other);
    bool isEquals(Block& other);

    bool isOverlapping(int x, int y);
    bool isOverlapping(Block& other);

    bool isTouching(int x, int y);
    bool isTouching(Block& other);

    bool isEquals(int x, int y);
    bool isOverlapping();
*/