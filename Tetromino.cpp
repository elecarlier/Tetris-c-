#include "Tetromino.hpp"

Tetromino::Tetromino() {}

std::array<Tetromino::Rotations, Tetromino::NUM_TYPE> Tetromino::generateAll() {
    std::array<Rotations, NUM_TYPE> allShapes{};
    for (int type = 0; type < NUM_TYPE; ++type) {
        allShapes[type] = generateShape(type);
    }
    return allShapes;
}

Tetromino::Rotations Tetromino::generateShape(int type)
{
    Rotations rotations{};
    //generating all the base cases
    Tetromino::Shape base{};
    switch (type) {
        case 0: //square
            base = {{
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0}
            }};
            break;
        case 1: //I
            base = {{
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 1, 2, 1, 1},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0}
            }};
            break;
        case 2: //L
            base = {{
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 2, 0, 0},
                {0, 0, 1, 1, 0},
                {0, 0, 0, 0, 0}
            }};
            break;
        case 3: //L mirrored
            base = {{
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 2, 0, 0},
                {0, 1, 1, 0, 0},
                {0, 0, 0, 0, 0}
            }};
            break;          
        case 4: //N 
            base = {{
                {0, 0, 0, 0, 0},
                {0, 0, 0, 1, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 0, 0}
            }};
            break;
        case 5: //N mirrored
            base = {{
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 2, 1, 0},
                {0, 0, 0, 1, 0},
                {0, 0, 0, 0, 0}
            }};
            break;
        case 6: //T
            base = {{
                {0, 0, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 1, 2, 1, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0}
            }};
            break;
    }

    rotations[0] = base;

    for (int i = 1; i < NUM_ROT; ++i)
        rotations[i] = rotate(rotations[i - 1]);
    return rotations;

}
/*Clockwise rotation 90grad*/
Tetromino::Shape Tetromino::rotate(const Shape& shape)
{
    Shape rotated{};

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            rotated[i][j] = shape[SIZE - j - 1][i];
    
    return rotated;
}