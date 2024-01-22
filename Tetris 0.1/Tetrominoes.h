#ifndef __TETROMINOES_H
#define __TETROMINOES_H

#include "Block.h"
#include "general.h"  // for rand()
#include "gameConfig.h" //for board size

#define BLOCKS_IN_SHAPE 4
#define MAX_SHAPE_ROTATIONS 4

/*
 * Squere Shape:
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

typedef enum {
    SquereShape = 0,
    LineShape,
    TShape,
    LShape,
    ReverseLShape,
    ZShape,
    ReverseZShape,
} ShapeType;

typedef enum
{
    currentRotation = 0,
    nextRotation = 1,
    PrevRotation = 2,
} rotationType;


class Tetrominoes // Shape
{
private:
    //The refrence point to start the shape
    int startingX = GameConfig::GAME_WIDTH / 2;
    // An array of all rotations of the tetromino.
    // Each rotation is represented as an array of Blocks.
    Block** rotations;
    int currentRotation;
    int color;
    ShapeType type; //Mostly for debugging

public:
    Tetrominoes();
    ~Tetrominoes();
    void lower();
    void moveRight();
    void moveLeft();
    void rotateClockwise();
    void rotateCounterClockwise();

    //bool isTouching(int x, int y);
    //bool isOverlapping(int x, int y); //Handle by board

    int GetBlockX(int blockNum, int rotation = 0) const; //rotation can be -1 or 1 for prev or next
    int GetBlockY(int blockNum, int rotation = 0) const;
    int getColor() const { return color; }
    int getRotation() const { return currentRotation; }
    ShapeType getType() const { return type; }

public: //Static functions that are related to tetrominoes
    static Block* createRotation(int arr[4][4], int midX);
    static void rotateMatrixClockwise(int matrix[4][4]);

};

#endif // !__TETROMINOES_H

/*
functions graveyard:
    Tetrominoes(Block blocks[BLOCKS_IN_SHAPE]);
    Tetrominoes(const Tetrominoes& other);
    Tetrominoes(int arr[4][4], int midX);
 static Tetrominoes[MAX_SHAPE_ROTATIONS] generateShapeRotations(ShapeType type); 

*/