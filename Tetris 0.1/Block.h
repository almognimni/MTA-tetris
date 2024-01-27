#ifndef __BLOCK_H
#define __BLOCK_H


// The Block class represents a basic block in a game

class Block {
    int x; // X-coordinate of the block
    int y; // Y-coordinate of the block

public:
    Block();  // Default constructor, initializes x and y to 0
  
    Block(int x, int y);   // Parameterized constructor, allows specifying initial x and y coordinates

    void lower();    // Move the block down by incrementing its y-coordinate

    void moveRight();     // Move the block to the right by incrementing its x-coordinate
     
    void moveLeft();     // Move the block to the left by decrementing its x-coordinate

    int getX() const;     // Getter for the x-coordinate of the block

    int getY() const;    // Getter for the y-coordinate of the block


};

#endif
