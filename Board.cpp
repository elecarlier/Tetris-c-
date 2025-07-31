#include "Board.hpp"

Board::Board() {
    InitBoard();

    for (int type = 0; type < Tetromino::NUM_TYPE; ++type) {
        allPieces[type] = Tetromino::generateShape(type);
    }
}

void Board::InitBoard() {
    for (int x = 0; x < BOARD_WIDTH; ++x)
        for (int y = 0; y < BOARD_HEIGHT; ++y)
            mBoard[x][y] = POS_FREE;
}

bool Board::IsFreeBlock(int x, int y) const {
    if (x < 0 || x >= BOARD_WIDTH || y < 0 || y >= BOARD_HEIGHT)
        return false;
    return mBoard[x][y] == POS_FREE;
}

void Board::PrintBoard() const {
    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            std::cout << (mBoard[x][y] == POS_FREE ? '.' : '#');
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
                    boardY >= 0 && boardY < BOARD_HEIGHT) {
                    mBoard[boardX][boardY] = POS_FILLED;
                }
            if (shape[i][j] == 2)
                std::cout << "Pivot placé à : (" << boardX << ", " << boardY << ")\n";
            }
        }
    }
}

