#ifndef __TETROMINOES_H
#define __TETROMINOES_H

#include "Block.h"
#include "general.h"  // for rand and colors
#include "gameConfig.h" //for board size

constexpr int BLOCKS_IN_TETROMINO = 4; // The amount of blocks in each tetromino
constexpr int MAX_TETROMINO_ROTATIONS = 4; // The maximum amount of rotations a tetromino can have

//Representations of the different tetrominos and their rotations:
/*
 * Squere Shape: | Line Shape  |  T Shape:           |  L Shape:          |  Reverse L Shape:   |  Reverse Z Shape: |  Z Shape:
 *  **           |          *  |  ***   *  *     *   |   *   **           |    *  **            |                   |         *
 *  **           |  ****    *  |   *   **  **   ***  |   *    *  *    *** |    *  *     *  ***  |    **   *         |   **   **
 *               |          *  |        *  *         |   **   *  ***  *   |   **  *   ***    *  |   **    **        |    **  *
 *               |          *  |                     |                    |                     |            *      |
 */


typedef enum
{
    SquereTetromino = 0,
    LineTetromino,
    T_Tetromino,
    LTetromino,
    ReverseLTetromino,
    ZTetromino,
    ReverseZTetromino,
} TetrominoType; // An enum representing the type of the tetromino (as seen in the illustration above)

typedef enum
{
    currentRotation = 0,
    nextRotation = 1,
    PrevRotation = 2,
} rotationType; // An enum representing which rotation we want to get the coordinates for (for collition checks)


class Tetrominoes
{
private:
    
    int startingX = GameConfig::GAME_WIDTH / 2; // The refrence point to spawn the tetromino on a board
    
    Block** rotations; // An array of all rotations of the tetromino, Each rotation is represented as an array of Blocks.

    int currentRotation; // Index for the current rotation (row) in the array

    int color; // Represents the color of the tetromino

    TetrominoType type; 

public:
    Tetrominoes(); //    The constructor for the tetrominos. Draws a number from 0 to 7 to determine the type, takes a matrix for each type and rotates it for it's rotations

    ~Tetrominoes(); //  The destructor, deletes the memory for each block

    void lower(); //    Lowers all the rotations by incrementing theire blocks y value

    void moveRight(); //    Moves all the rotations by incrementing the blocks x value

    void moveLeft(); //     Moves all the rotations by decrementing the blocks x value

    void rotateClockwise(); //  Makes the current rotation go "up" by one (uses % to keep it between 0-3)

    void rotateCounterClockwise(); //   Makes the current rotation go "down" by one (uses % to keep it between 0-3)

    int GetBlockX(int blockNum, int rotation = 0) const; // Gets a single block X value given its number and rotation
                                                         // (Rotation can be -1 or 1 for prev or next)
    int GetBlockY(int blockNum, int rotation = 0) const; // Gets a single block Y value given its number and rotation

    int getColor() const { return color; } // Get method for the tetromino color

    int getRotation() const { return currentRotation; } // Get method for the tetromino current rotation

    TetrominoType getType() const { return type; } // Get method for the tetromino type


public: //Static functions that are related to tetrominoes

    static Block* createRotation(int arr[4][4], int midX); // Creates a single rotation (array of blocks) given a matrix representing the tetromino and a refrence point

    static void rotateMatrixClockwise(int matrix[4][4]); // Method to rotate a 4x4 matrix clockwise. Used to create the differant rotations

};

#endif
