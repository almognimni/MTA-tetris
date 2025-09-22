#include "Tetrominoes.h"


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

/**
 * @brief Creates a rotation state from a 4x4 matrix pattern
 * @param arr 4x4 integer array where 1 represents a block, 0 represents empty space
 * @param midX Starting X position for the shape (center reference point)
 * @return Pointer to array of Block objects representing this rotation state
 * 
 * This function converts a 4x4 matrix representation of a tetromino shape into
 * an array of Block objects. It scans the matrix row by row, creating Block
 * objects for each position marked with 1. The midX parameter serves as a
 * reference point for positioning the blocks relative to the board center.
 * 
 * Memory allocation: This function allocates memory that must be freed when
 * the tetromino is destroyed or placed on the board.
 */
Block* Tetrominoes::createRotation(int arr[4][4], int midX)
{
    Block* rotation = new Block[BLOCKS_IN_SHAPE];
    int blockIndex = 0;

    // Scan the 4x4 matrix to find block positions
    for (int row = 0; row < BLOCKS_IN_SHAPE; row++)
    {
        for (int col = 0; col < BLOCKS_IN_SHAPE; col++)
        {
            // Safety check: stop if we already have 4 blocks
            if (blockIndex >= BLOCKS_IN_SHAPE)
                return rotation;

            // Create a block for each '1' in the matrix
            if (arr[row][col] == 1)
            {
                // Position block relative to midX reference point
                rotation[blockIndex] = Block(midX - 1 + col, row);
                blockIndex++;
            }
        }
    }
    return rotation;
}

/**
 * @brief Constructor - creates a random tetromino with all rotation states
 * 
 * Randomly selects one of the seven tetromino types, assigns appropriate color,
 * and generates all four rotation states for that shape type.
 */
Tetrominoes::Tetrominoes()
{
    shapeType = (ShapeType)(rand() % 7); //////19_01_24  maor add casting
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

/*
int* Tetrominoes::getCurrentRotationPos() //*******TODO*******
{
    block[] 
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++)
    {
        rotations[currentRotation][i].getX();
    }
}
*/

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

/**
 * @brief Rotates the tetromino clockwise to the next rotation state
 * 
 * Advances the currentRotation index by 1, wrapping around to 0 when
 * reaching the maximum rotation states. The modulo operation ensures
 * the rotation index stays within valid bounds (0 to MAX_SHAPE_ROTATIONS-1).
 */
void Tetrominoes::rotateClockwise()
{
	this->currentRotation = ((this->currentRotation + 1)) + MAX_SHAPE_ROTATIONS % MAX_SHAPE_ROTATIONS;
}

/**
 * @brief Rotates the tetromino counter-clockwise to the previous rotation state
 * 
 * Note: Currently has the same implementation as clockwise rotation - this appears
 * to be a bug that needs fixing. Should subtract 1 instead of adding 1.
 * TODO: Fix counter-clockwise rotation to actually rotate in opposite direction
 */
void Tetrominoes::rotateCounterClockwise()
{
	this->currentRotation = ((this->currentRotation + 1)) + MAX_SHAPE_ROTATIONS % MAX_SHAPE_ROTATIONS;
}

/**
 * @brief Gets the X coordinate of a specific block with optional rotation offset
 * @param blockNum Index of the block within the tetromino (0-3)
 * @param rotationMod Rotation offset from current state (-1, 0, or 1)
 * @return X coordinate of the specified block in the specified rotation
 * 
 * The rotation calculation uses modulo arithmetic to handle negative values correctly
 * and ensure the rotation index wraps around within valid bounds.
 */
int Tetrominoes::GetBlockX(int blockNum, int rotationMod) const
{
    // Calculate target rotation with proper wrap-around handling
    int blockRotation = ((currentRotation + rotationMod) + MAX_SHAPE_ROTATIONS) % MAX_SHAPE_ROTATIONS;

    return this->rotations[blockRotation][blockNum].getX();
}

/**
 * @brief Gets the Y coordinate of a specific block with optional rotation offset
 * @param blockNum Index of the block within the tetromino (0-3)
 * @param rotationMod Rotation offset from current state (-1, 0, or 1)
 * @return Y coordinate of the specified block in the specified rotation
 */
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


/*
Coilition functions will be implemented in the board class


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