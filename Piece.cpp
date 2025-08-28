#include "Piece.hpp"


Piece::Piece(int t) : type(t), rotation(0), x(BOARD_WIDTH / 2), y(0) {}

void Piece::MoveLeft()
{
    --x;
}

void Piece::MoveRight()
{
    ++x;
}

void Piece::MoveDown()
{
    ++y;
}

void Piece::MoveUp()
{
    --y;
}

void Piece::Rotate()
{
    rotation = (rotation + 1) % Tetromino::NUM_ROT;
}
void Piece::RotateBack()
{
     rotation = (rotation + Tetromino::NUM_ROT - 1) % Tetromino::NUM_ROT;
}


int Piece::GetX() const
{
    return x;
}

int Piece::GetY() const
{
    return y;
}

int Piece::GetRotation() const
{
    return rotation;
}

int Piece::GetType() const
{
    return type;
}

void Piece::SetPosition(int newX, int newY)
{
    x = newX;
    y = newY;
}

void Piece::SetRotation(int r)
{
    rotation = r % Tetromino::NUM_ROT;
}

/*
Generating all the shapes and rotations for now, but can use the one from the board later

Return vector of all the coordinate of the piece
*/
std::vector<std::pair<int, int>> Piece::GetBlocks() const
{
    std::vector<std::pair<int,int>> blocks;

    //Tetromino::Rotations rotations = Tetromino::generateShape(type);
    const Tetromino::Shape shape = Tetromino::generateAll()[type][rotation];
    for (int i = 0; i < Tetromino::SIZE; ++i) {
        for (int j = 0; j < Tetromino::SIZE; ++j) {
            if (shape[i][j] != 0) {
                int boardX = x + (j - pivot_j);
                int boardY = y + (i - pivot_i);
                blocks.push_back(std::make_pair(boardX, boardY));
            }
        }
    }
    return blocks;
}

bool Piece::IsPivot(int blockX, int blockY) const
{
    return (blockX == x && blockY == y);
}
