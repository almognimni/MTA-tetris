#ifndef __TETROMINOES_H
#define __TETROMINOES_H

#include "Block.h"
#include <cstdlib>  // for rand()

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
    Tetrominoes(const Tetrominoes& other);
    Tetrominoes(int arr[4][4], int midX);
    Tetrominoes(); //I need you to build Empty con that use random to give me shape
    void lower();
    void moveRight();
    void moveLeft();
    bool isTouching(int x, int y);
    bool isOverlapping(int x, int y);

public:

    //you need to check the signature of the function

    static Tetrominoes[MAX_SHAPE_ROTATIONS] generateShapeRotations(ShapeType type); 
};


#endif // !__TETROMINOES_H