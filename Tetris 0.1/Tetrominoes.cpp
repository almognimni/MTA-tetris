#include "Tetrominoes.h"
#include <cstdlib>


/*
Tetrominoes::Tetrominoes(Block _blocks[BLOCKS_IN_SHAPE]) {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++) {
        this->blocks[i] = _blocks[i];
    }
}

Tetrominoes::Tetrominoes(const Tetrominoes& other) {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++) {
        this->blocks[i] = Block(other.blocks[i]);
    }
}
*/

/*Tetrominoes::Tetrominoes(int arr[4][4], int midX) {
    int k = 0;
    for (int y = 0; y < BLOCKS_IN_SHAPE; y++)
    {
        for (int x = 0; x < BLOCKS_IN_SHAPE; x++)
        {
            if (k >= 4)
            {
                return;
            }

            if (arr[y][x] == 1)
            {
                this->blocks[k] = Block(midX - 1 + x, y);
                k++;
            }
        }
    }
}
*/


/*The marked "1" is the middle x:
        // {
        //     { 1, *1*, 1, 1 },
        //     { 0, 0, 0, 0 },
        //     { 0, 0, 0, 0 },
        //     { 0, 0, 0, 0 },
        // }
        */

//Function will take an 4x4 matrix representing a shape and a starting point and will create an array of 4 blocks representing it
Block* createRotation(int arr[4][4], int midX) {
    Block rotation[BLOCKS_IN_SHAPE];
    int i = 0;

    for (int row = 0; row < BLOCKS_IN_SHAPE; row++)
    {
        for (int col = 0; col < BLOCKS_IN_SHAPE; col++)
        {
            if (i >= BLOCKS_IN_SHAPE)
                return;

            if (arr[row][col] == 1)
            {
                rotation[i] = Block(midX - 1 + col, row);
                i++;
            }
        }
    }
    return rotation;
}

Tetrominoes::Tetrominoes() {
    ShapeType shapeType = rand() % 7;
    currentRotation = 0;

    switch (shapeType)
    {
    case ShapeType::SquereShape:
        int square[4][4] = {
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0},
            {0,0,0,0}
        };

        for (int i = 0; i < MAX_SHAPE_ROTATIONS; i++) {
            rotations[i] = createRotation(square, middleX);
        }
        break;

    case ShapeType::LineShape:
        int line1[4][4] = {
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
        };
        rotations[0] = createRotation(line1, middleX);
        rotations[2] = rotations[0];

        int line2[4][4] = {
            {0,0,0,1},
            {0,0,0,1},
            {0,0,0,1},
            {0,0,0,1}
        };
        rotations[1] = createRotation(line2, middleX);
        rotations[3] = rotations[1];

        break;

    case ShapeType::TShape:
        int T[4][4] = {
            {1,1,1,0},
            {0,1,0,0},
            {0,0,0,0},
            {0,0,0,0}
        };
        rotations[0] = createRotation(T, middleX);

        for (int i = 1; i < 4; i++)
        {
            rotateMatrixClockwise(T);
            rotations[i] = createRotation(T, middleX);
        }

        break;

    case ShapeType::LShape:
        int L[4][4] = {
            {1,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {0,0,0,0}
        };

        rotations[0] = createRotation(L, middleX);
        for (int i = 1; i < 4; i++)
        {
            rotateMatrixClockwise(L);
            rotations[i] = createRotation(L, middleX);
        }

        break;

    case ShapeType::ReverseLShape:
        int rL[4][4] = {
            {0,0,0,1},
            {0,0,0,1},
            {0,0,1,1},
            {0,0,0,0}
        };

        rotations[0] = createRotation(rL, middleX);
        for (int i = 1; i < 4; i++)
        {
            rotateMatrixClockwise(L);
            rotations[i] = createRotation(rL, middleX);
        }

        break;

    case ShapeType::ZShape:
        int Z[4][4] = {
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0},
            {0,0,0,0}
        };
        rotations[0] = createRotation(Z, middleX);
        rotations[2] = rotations[0];

        rotateMatrixClockwise(Z);
        rotations[1] = createRotation(Z, middleX);
        rotations[3] = rotations[1];

        break;

    case ShapeType::ReverseZShape:
        int rZ[4][4] = {
            {0,1,1,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0}
        };
        rotations[0] = createRotation(rZ, middleX);
        rotations[2] = rotations[0];

        rotateMatrixClockwise(Z);
        rotations[1] = createRotation(rZ, middleX);
        rotations[3] = rotations[1];

        break;
    }
}

int* Tetrominoes::getCurrentRotationPos() //TODO
{
    
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
    {
        rotations[currentRotation][i].getX;
    }
}


void rotateMatrixClockwise(int matrix[4][4]) {
    for (int i = 0; i < 4 / 2; i++) {
        for (int j = i; j < 4 - i - 1; j++) {
            int temp = matrix[i][j];
            // Move values from left to top
            matrix[i][j] = matrix[4 - 1 - j][i];
            // Move values from bottom to left
            matrix[4 - 1 - j][i] = matrix[4 - 1 - i][4 - 1 - j];
            // Move values from right to bottom
            matrix[4 - 1 - i][4 - 1 - j] = matrix[j][4 - 1 - i];
            // Assign temp to right
            matrix[j][4 - 1 - i] = temp;
        }
    }
}

//Will need to change those
void Tetrominoes::lower() {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++) {
        this->blocks[i].lower();
    }
}

void Tetrominoes::moveRight() {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++) {
        this->blocks[i].moveRight();
    }
}

void Tetrominoes::moveLeft() {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++) {
        this->blocks[i].moveLeft();
    }
}




/*

bool Tetrominoes::isTouching(int x, int y) {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++) {
        if (this->blocks[i].isTouching(x, y)) {
            return true;
        }
    }

    return false;
}
bool Tetrominoes::isOverlapping(int x, int y) {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++) {
        if (this->blocks[i].isEquals(x, y)) {
            return true;
        }
    }

    return false;
 }

//you need to check the signature of the function
static Tetrominoes[MAX_SHAPE_ROTATIONS] Tetrominoes::generateShapeRotations(ShapeType type, int xStart) {
    Tetrominoes rotations[MAX_SHAPE_ROTATIONS];
    Block blocks[4];
    int leftUpperX = xStart, leftUpperY = 0;

       0,0-------------------
        |       **
        |       **
        |
        |
        |
        |


    switch (type)
    {
    case ShapeType::SquereShape:
        Tetrominoes square = Tetrominoes({
            {},
            {},
            {},
            {},
        });
        for (int i = 0; i < MAX_SHAPE_ROTATIONS; i++) {
            rotations[i] = Tetrominoes(square);
        }
        break;
    case ShapeType::LineShape:
        blocks[0] = Block(leftUpperX, leftUpperY);
        blocks[1] = Block(leftUpperX + 1, leftUpperY);
        blocks[2] = Block(leftUpperX + 2, leftUpperY);
        blocks[3] = Block(leftUpperX + 3, leftUpperY);
        Tetrominoes horizontal = Tetrominoes(blocks);

        blocks[0] = Block(leftUpperX, leftUpperY);
        blocks[1] = Block(leftUpperX, leftUpperY + 1);
        blocks[2] = Block(leftUpperX, leftUpperY + 2);
        blocks[3] = Block(leftUpperX, leftUpperY + 3);
        Tetrominoes vertical = Tetrominoes(blocks);

        rotations[0] = Tetrominoes(horizontal);
        rotations[1] = Tetrominoes(vertical);
        rotations[2] = Tetrominoes(horizontal);
        rotations[3] = Tetrominoes(vertical);
        break;
    case ShapeType::TShape:
        break;
    case ShapeType::LShape:
        break;
    case ShapeType::ReverseLShape:
        break;
    case ShapeType::ZShape:
        Tetrominoes base = Tetrominoes();
        Tetrominoes rotated = Tetrominoes();
        rotations[0] = Tetrominoes(base);
        rotations[1] = Tetrominoes(rotated);
        rotations[2] = Tetrominoes(base);
        rotations[3] = Tetrominoes(rotated);
        break;
    case ShapeType::ReverseZShape:
        break;
    }
    

	return rotations;
}
*/