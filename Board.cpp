#include "Board.hpp"

Board::Board() {
    InitBoard();

    for (int type = 0; type < Tetromino::NUM_TYPE; ++type) {
        allPieces[type] = Tetromino::generateShape(type);
    }
}

void Board::InitBoard() {
    for (int y = 0; y < BOARD_HEIGHT; ++y)
        for (int x = 0; x < BOARD_WIDTH; ++x)
            mBoard[y][x] = POS_FREE;
}

bool Board::IsFreeBlock(int x, int y) const {
    if (x < 0 || x >= BOARD_WIDTH || y < 0 || y >= BOARD_HEIGHT)
        return false;
    return mBoard[y][x] == POS_FREE;
}

void Board::PrintBoard() const {
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            std::cout << (mBoard[y][x] == POS_FREE ? '.' : '#');
            //std::cout << mBoard[y][x]; 
        }
        std::cout << '\n';
    }
}

/*Store a piece at px, py position
    using the pivot as the position */
void Board::StorePiece(int pX, int pY, int pPieceType, int pRotation)
{
    const auto& shape = allPieces[pPieceType][pRotation];
    const int pivot_i = 2;
    const int pivot_j = 2;

    for (int i = 0; i < Tetromino::SIZE; ++i) {
        for (int j = 0; j < Tetromino::SIZE; ++j) {

            if (shape[i][j] != 0) {
                int boardY = pY + (i - pivot_i);
                int boardX = pX + (j - pivot_j);

                if (boardX >= 0 && boardX < BOARD_WIDTH &&
                    boardY >= 0 && boardY < BOARD_HEIGHT)  {
                    mBoard[boardY][boardX] = POS_FILLED;
                }
            }
        }
    }
}


bool Board::IsPossibleMovement (int pX, int pY, int pPiece, int pRotation)
{
    //to do 
}

//If the first line has blocks, then, game over
bool Board::IsGameOver() const
{

    for (int x = 0; x < BOARD_WIDTH; x++)
    {
        if (mBoard[0][x] == POS_FILLED) return true;
    }

    return false;
}

/*py: height of the line to delete 
delete a line and moves down all the blocs above*/
void Board::DeleteLine(int py)
{
    for (int y = py; y > 0; --y)
    {
        for (int x = 0; x < BOARD_WIDTH; ++x)
            mBoard[y][x] = mBoard[y-1][x];
    }

    for (int x = 0; x < BOARD_WIDTH; ++x)
        mBoard[0][x] = POS_FREE;
}



void Board::DeletePossibleLines()
{
    for (int y = 0; y < BOARD_HEIGHT; ++y)
    {
        int filled = 0;
        for (int x = 0; x < BOARD_WIDTH; ++x)
        {
            if (mBoard[y][x] == POS_FILLED)
                filled++;
        }  
        if ( filled == BOARD_WIDTH)
        {
            DeleteLine(y);
            --y;
        } 
            
    }   
}

void Board::DebugFillLine(int y) {
    for (int x = 0; x < BOARD_WIDTH; ++x) {
        mBoard[y][x] = POS_FILLED;
    }
}
