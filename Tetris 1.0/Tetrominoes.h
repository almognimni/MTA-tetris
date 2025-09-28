/**
 * @file Tetrominoes.h
 * @brief Definition of Tetris game pieces (tetrominoes) and their behavior
 * 
 * This file contains the Tetrominoes class which represents the falling pieces
 * in Tetris. Each tetromino has multiple rotations and can be moved and rotated
 * during gameplay. The file also defines the different types of Tetris shapes.
 */

#ifndef __TETROMINOES_H
#define __TETROMINOES_H

#include "Block.h"
#include "general.h"  // for rand()
#include "gameConfig.h" //for board size

/** @brief Number of blocks that make up each tetromino shape */
constexpr int BLOCKS_IN_SHAPE = 4;

/** @brief Maximum number of rotation states for any tetromino */
constexpr int MAX_SHAPE_ROTATIONS = 4;

/**
 * @brief Visual representation of all tetromino shapes and their rotations
 * 
 * Square Shape:
 *  **
 *  **
 *
 * Line Shape:
 *          *
 *  ****    *
 *          *
 *          *
 *
 * T Shape:
 * ***   *  *     *
 *  *   **  **   ***
 *       *  *    
 *
 * L Shape:
 *  *   **     
 *  *    *  *    ***
 *  **   *  ***  * 
 *
 * Reverse L Shape:
 *   *  **  
 *   *  *     *  ***
 *  **  *   ***    *
 *
 * Reverse Z Shape:
 *          
 *   **   *   
 *  **    **   
 *         *
 *
 * Z Shape:
 *        *
 *  **   **
 *   **  *
 */

/**
 * @brief Enumeration of all tetromino shape types
 * 
 * Defines the seven standard Tetris piece types, each with distinct
 * geometric properties and rotation behaviors.
 */
typedef enum {
    SquereShape = 0,     ///< Square/O-piece (2x2 square)
    LineShape,           ///< Line/I-piece (4x1 line)
    TShape,              ///< T-piece (T-shaped)
    LShape,              ///< L-piece (L-shaped)
    ReverseLShape,       ///< Reverse L-piece (J-piece)
    ZShape,              ///< Z-piece (Z-shaped)
    ReverseZShape,       ///< Reverse Z-piece (S-piece)
} ShapeType;

/**
 * @brief Enumeration for rotation state references
 * 
 * Used to specify which rotation state to access relative to the current state.
 */
typedef enum
{
    currentRotation = 0,  ///< Current rotation state
    nextRotation = 1,     ///< Next rotation state (clockwise)
    PrevRotation = 2,     ///< Previous rotation state (counter-clockwise)
} rotationType;


/**
 * @brief Class representing a Tetris piece (tetromino)
 * 
 * The Tetrominoes class manages individual Tetris pieces, including their position,
 * rotation state, color, and movement. Each tetromino consists of 4 blocks arranged
 * in a specific pattern and can be rotated through up to 4 different orientations.
 */
class Tetrominoes // Shape
{
private:
    /** @brief Starting X position when piece spawns (middle of board) */
    int startingX = GameConfig::GAME_WIDTH / 2;
    
    /** @brief Array of all rotation states for this tetromino */
    Block** rotations;
    
    /** @brief Current rotation state index (0-3) */
    int currentRotation;
    
    /** @brief Color code for rendering this piece */
    int color;
    
    /** @brief Type of shape this tetromino represents */
    ShapeType shapeType; ///< Mostly for debugging purposes

public:
    /**
     * @brief Default constructor - creates a random tetromino
     * 
     * Randomly selects a shape type and initializes all rotation states
     * for that shape with appropriate color and positioning.
     */
    Tetrominoes();
    
    /**
     * @brief Destructor - cleans up allocated memory for rotations
     */
    ~Tetrominoes();
    
    /**
     * @brief Moves the tetromino down by one row
     */
    void lower();
    
    /**
     * @brief Moves the tetromino right by one column
     */
    void moveRight();
    
    /**
     * @brief Moves the tetromino left by one column
     */
    void moveLeft();
    
    /**
     * @brief Rotates the tetromino clockwise to next rotation state
     */
    void rotateClockwise();
    
    /**
     * @brief Rotates the tetromino counter-clockwise to previous rotation state
     */
    void rotateCounterClockwise();

    //bool isTouching(int x, int y);
    //bool isOverlapping(int x, int y); // Collision detection handled by board

    /**
     * @brief Gets the X coordinate of a specific block in the tetromino
     * @param blockNum Index of the block (0-3)
     * @param rotation Rotation offset from current state (-1, 0, or 1)
     * @return X coordinate of the specified block
     */
    int GetBlockX(int blockNum, int rotation = 0) const;
    
    /**
     * @brief Gets the Y coordinate of a specific block in the tetromino
     * @param blockNum Index of the block (0-3) 
     * @param rotation Rotation offset from current state (-1, 0, or 1)
     * @return Y coordinate of the specified block
     */
    int GetBlockY(int blockNum, int rotation = 0) const;
    
    /**
     * @brief Gets the color code for this tetromino
     * @return Color code used for rendering
     */
    int getColor() const { return color; }
    
    /**
     * @brief Gets the current rotation state index
     * @return Current rotation state (0-3)
     */
    int getRotation() const { return currentRotation; }
    
    /**
     * @brief Gets the shape type of this tetromino
     * @return ShapeType enumeration value
     */
    ShapeType getType() const { return shapeType; }

public: // Static functions that are related to tetrominoes
    /**
     * @brief Creates a rotation state from a 4x4 matrix pattern
     * @param arr 4x4 integer array representing the shape pattern
     * @param midX Starting X position for the shape
     * @return Pointer to array of Block objects representing this rotation
     */
    static Block* createRotation(int arr[4][4], int midX);
    
    /**
     * @brief Rotates a 4x4 matrix 90 degrees clockwise
     * @param matrix 4x4 integer matrix to rotate
     */
    static void rotateMatrixClockwise(int matrix[4][4]);

};

#endif // !__TETROMINOES_H

/**
 * @brief Functions graveyard - deprecated/unused function signatures
 * 
 * These function signatures were used in earlier versions but are no longer
 * needed in the current implementation:
 * 
 * - Tetrominoes(Block blocks[BLOCKS_IN_SHAPE]): Constructor from block array
 * - Tetrominoes(const Tetrominoes& other): Copy constructor  
 * - Tetrominoes(int arr[4][4], int midX): Constructor from matrix pattern
 * - static Tetrominoes[MAX_SHAPE_ROTATIONS] generateShapeRotations(ShapeType type): Factory function
 */