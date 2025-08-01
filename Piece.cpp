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
void Piece::Rotate()
{

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

}

void Piece::SetPosition(int newX, int newY)
{

}

void Piece::SetRotation(int rotation)
{

}


std::vector<std::pair<int, int>> Piece::GetBlocks() const
{

}


