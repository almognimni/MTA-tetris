#pragma once

class Block {
    int x;
    int y;
public:
    Block(int x, int y);
    Block(Block& other);
    void lower();
    bool isTouching(int x, int y);
    bool isTouching(Block& other);
    bool isEquals(int x, int y);
    bool isEquals(Block& other);
};

