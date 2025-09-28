/**
 * @file Block.h
 * @brief Individual block component for Tetris pieces
 * 
 * This file contains the Block class which represents a single square unit
 * that makes up tetromino pieces. Each block has position coordinates and
 * can be moved independently.
 */

#ifndef __BLOCK_H
#define __BLOCK_H

class Board; // Forward declaration

/**
 * @brief Individual block component of a tetromino piece
 * 
 * The Block class represents a single square unit with x,y coordinates.
 * Four blocks combine to form each tetromino piece. Blocks can be moved
 * and positioned independently.
 */
class Block {
    int x;  ///< X coordinate (column position)
    int y;  ///< Y coordinate (row position)

public:
    /**
     * @brief Default constructor - creates block at origin (0,0)
     */
    Block();
    
    /**
     * @brief Constructor with position
     * @param x Initial X coordinate
     * @param y Initial Y coordinate
     */
    Block(int x, int y);
    
    /**
     * @brief Moves the block down by one row
     */
    void lower();
    
    /**
     * @brief Moves the block right by one column
     */
    void moveRight();
    
    /**
     * @brief Moves the block left by one column
     */
    void moveLeft();
    
    /**
     * @brief Gets the current X coordinate
     * @return X coordinate value
     */
    int getX() const;
    
    /**
     * @brief Gets the current Y coordinate
     * @return Y coordinate value  
     */
    int getY() const;

};

#endif

/**
 * @brief Collision detection is handled by the board class
 * 
 * The following functions were considered but collision detection
 * is managed centrally by the Board class for better coordination:
 * 
 * Function graveyard - deprecated/unused function signatures:
 * - Block(const Block& other): Copy constructor
 * - bool isEquals(Block& other): Equality comparison
 * - bool isOverlapping(int x, int y): Position overlap check
 * - bool isOverlapping(Block& other): Block overlap check  
 * - bool isTouching(int x, int y): Position adjacency check
 * - bool isTouching(Block& other): Block adjacency check
 * - bool isEquals(int x, int y): Position equality check
 * - bool isOverlapping(): Default overlap check
 */