#ifndef __BLOCK_H
#define __BLOCK_H


class Block {
    int x;
    int y;

public:
    Block();
    Block(int x, int y);
    Block(const Block& other);
    void lower();
    void moveRight();
    void moveLeft();
    bool isTouching(int x, int y);
    bool isTouching(Block& other);
    bool isEquals(int x, int y);
    bool isEquals(Block& other);
    bool isOverlapping(int x, int y);
    bool isOverlapping(Block& other);

    
};

#endif
