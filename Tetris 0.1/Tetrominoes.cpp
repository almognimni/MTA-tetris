#include "Tetrominoes.h"


/*The marked "1" is the middle x:
        // {
        //     { 1, *1*, 1, 1 },
        //     { 0, 0, 0, 0 },
        //     { 0, 0, 0, 0 },
        //     { 0, 0, 0, 0 },
        // }
        */

//Function will take an 4x4 matrix representing a shape and a starting point and will create an array of 4 blocks representing it
Block* Tetrominoes::createRotation(int arr[4][4], int midX)
{
    Block* rotation = new Block[BLOCKS_IN_SHAPE];
    int i = 0;

    for (int row = 0; row < BLOCKS_IN_SHAPE; row++)
    {
        for (int col = 0; col < BLOCKS_IN_SHAPE; col++)
        {
            if (i >= BLOCKS_IN_SHAPE)
                return rotation; //If we have 4 blocks we return the tetromino

            if (arr[row][col] == 1)
            {
                rotation[i] = Block(midX - 1 + col, row);
                i++;
            }
        }
    }
    return rotation;
}
//TODO - free the memory after a shape has been placed on the board
//Create a free function that will free the rotations of a shape

Tetrominoes::Tetrominoes()
{
    ShapeType shapeType = (ShapeType)(rand() % 7); //////19_01_24  maor add casting
    currentRotation = 0;
    rotations = new Block* [MAX_SHAPE_ROTATIONS];
    switch (shapeType)
    {
    case ShapeType::SquereShape:
    {

        color = GameConfig::COLORS[1];
        int square[4][4] = {
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0},
            {0,0,0,0}
        };
        for (int i = 0; i < MAX_SHAPE_ROTATIONS; i++) {
            rotations[i] = createRotation(square, startingX);
        }
        break;
    }

    case ShapeType::LineShape:
    {
        color = GameConfig::COLORS[2];

        int line1[4][4] = {
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
        };
        rotations[0] = createRotation(line1, startingX);
        rotations[2] = createRotation(line1, startingX);

        int line2[4][4] = {
            {0,0,1,0},
            {0,0,1,0},
            {0,0,1,0},
            {0,0,1,0}
        };
        rotations[1] = createRotation(line2, startingX);
        rotations[3] = createRotation(line2, startingX);

        break;
    }

    case ShapeType::TShape:
    {
        color = GameConfig::COLORS[3];

        int T[4][4] = {
            {1,1,1,0},
            {0,1,0,0},
            {0,0,0,0},
            {0,0,0,0}
        };
        rotations[0] = createRotation(T, startingX);

        for (int i = 1; i < 4; i++)
        {
            rotateMatrixClockwise(T);
            rotations[i] = createRotation(T, startingX);
        }

        break;
    }

    case ShapeType::LShape:
    {
        color = GameConfig::COLORS[4];

        int L[4][4] = {
            {1,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {0,0,0,0}
        };

        rotations[0] = createRotation(L, startingX);
        for (int i = 1; i < 4; i++)
        {
            rotateMatrixClockwise(L);
            rotations[i] = createRotation(L, startingX);
        }

        break;
    }

    case ShapeType::ReverseLShape:
    {
        color = GameConfig::COLORS[5];

        int rL[4][4] = {
            {0,0,0,1},
            {0,0,0,1},
            {0,0,1,1},
            {0,0,0,0}
        };

        rotations[0] = createRotation(rL, startingX);
        for (int i = 1; i < 4; i++)
        {
            rotateMatrixClockwise(rL);
            rotations[i] = createRotation(rL, startingX);
        }

        break;
    }
    case ShapeType::ZShape:
    {
        color = GameConfig::COLORS[6];

        int Z[4][4] = {
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0},
            {0,0,0,0}
        };
        rotations[0] = createRotation(Z, startingX);
        rotations[2] = createRotation(Z, startingX);        

        rotateMatrixClockwise(Z);
        rotations[1] = createRotation(Z, startingX);
        rotations[3] = createRotation(Z, startingX);

        break;
    }

    case ShapeType::ReverseZShape:
    {
        color = GameConfig::COLORS[7];

        int rZ[4][4] = {
            {0,1,1,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0}
        };
        rotations[0] = createRotation(rZ, startingX);
        rotations[2] = createRotation(rZ, startingX); 

        rotateMatrixClockwise(rZ);
        rotations[1] = createRotation(rZ, startingX);
        rotations[3] = createRotation(rZ, startingX);

        break;
    }
    }
}

void Tetrominoes::rotateMatrixClockwise(int matrix[4][4])
{
    for (int i = 0; i < 4 / 2; i++)
    {
        for (int j = i; j < 4 - i - 1; j++)
        {
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

//Moves all rotations down
void Tetrominoes::lower() {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
    {
        for (int j = 0; j < BLOCKS_IN_SHAPE; j++)
        {
            this->rotations[i][j].lower();
        }
    }
}

//Moves all rotations to the right
void Tetrominoes::moveRight() {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
    {
    for (int j = 0; j < BLOCKS_IN_SHAPE; j++)
    {
        this->rotations[i][j].moveRight();
    }
        
    }
}

//Moves all rotations to the left
void Tetrominoes::moveLeft() {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
    {
        for (int j = 0; j < BLOCKS_IN_SHAPE; j++)
        {
        this->rotations[i][j].moveLeft();
        }
    }
}

//Rotate the shape clockwise
void Tetrominoes::rotateClockwise()
{
	this->currentRotation = ((this->currentRotation + 1) + MAX_SHAPE_ROTATIONS) % MAX_SHAPE_ROTATIONS;
}

//Rotate the shape counter-clockwise
void Tetrominoes::rotateCounterClockwise()
{
	this->currentRotation = ((this->currentRotation - 1) + MAX_SHAPE_ROTATIONS) % MAX_SHAPE_ROTATIONS;
}

int Tetrominoes::GetBlockX(int blockNum, int rotationMod) const
{
    int blockRotation = ((currentRotation + rotationMod) + MAX_SHAPE_ROTATIONS) % MAX_SHAPE_ROTATIONS; // Must explain

    return this->rotations[blockRotation][blockNum].getX();
}

int Tetrominoes::GetBlockY(int blockNum, int rotationMod) const
{
    int blockRotation = ((currentRotation + rotationMod) + MAX_SHAPE_ROTATIONS) % MAX_SHAPE_ROTATIONS;
    return this->rotations[blockRotation][blockNum].getY();
}

 Tetrominoes::~Tetrominoes()
{
    for (int i = 0; i < MAX_SHAPE_ROTATIONS; i++)
    {
		delete[] rotations[i];
	}
	delete[] rotations;
}
