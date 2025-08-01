
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include "Tetromino.hpp"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

class Board {
        public:
        enum { POS_FREE = 0, POS_FILLED = 1 };

        Board();

        bool IsFreeBlock(int x, int y) const;
        void PrintBoard() const;
        void StorePiece(int pX, int pY, int pPiece, int pRotation);
        bool IsGameOver() const;
        void DeletePossibleLines();
        void DeleteLine(int py);
        void DebugFillLine(int y);
        void IsPossibleMovement (int pX, int pY, int pPiece, int pRotation);

    private:

        void InitBoard();
        int mBoard[BOARD_HEIGHT][BOARD_WIDTH];
        std::array<Tetromino::Rotations, Tetromino::NUM_TYPE> allPieces;
};

#endif
