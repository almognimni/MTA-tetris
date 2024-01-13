#include "Tetrominoes.h"



Tetrominoes::Tetrominoes(Block _blocks[BLOCKS_IN_SHAPE]) {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++) {
        this->blocks[i] = _blocks[i];
    }
}

Tetrominoes::Tetrominoes(Tetrominoes& other) {
    for (int i = 0; i < BLOCKS_IN_SHAPE; i++) {
        this->blocks[i] = Block(other.blocks[i]);
    }
}

        // {
        //     { 1, *1*, 1, 1 },
        //     { 0, 0, 0, 0 },
        //     { 0, 0, 0, 0 },
        //     { 0, 0, 0, 0 },
        // }
Tetrominoes::Tetrominoes(int arr[4][4], int midX) {
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

static Tetrominoes[MAX_SHAPE_ROTATIONS] Tetrominoes::generateShapeRotations(ShapeType type, int xStart) {
    Tetrominoes rotations[MAX_SHAPE_ROTATIONS];
    Block blocks[4];
    int leftUpperX = xStart, leftUpperY = 0;

    /*
       0,0-------------------
        |       **
        |       **
        |
        |
        |
        |
    */

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