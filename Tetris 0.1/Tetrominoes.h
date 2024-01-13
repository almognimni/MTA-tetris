#ifndef TETROMINOES_H
#define TETROMINOES_H

#include "Block.h"

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


class Tetrominoes // Shape
{
private:
	Block blocks[BLOCKS_IN_SHAPE];

public:
    Tetrominoes(Block blocks[BLOCKS_IN_SHAPE]);
    Tetrominoes(Tetrominoes& other);
    Tetrominoes(int arr[4][4], int midX);
    void lower();
    void moveRight();
    void moveLeft();
    bool isTouching(int x, int y);
    bool isOverlapping(int x, int y);

public:
    static Tetrominoes[MAX_SHAPE_ROTATIONS] generateShapeRotations(ShapeType type);
};


#endif // !TETROMINOES_H