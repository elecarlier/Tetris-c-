#ifndef BOARD_HPP
#define BOARD_HPP

class Piece;

#include <iostream>
#include "Tetromino.hpp"
#include "Piece.hpp"
#include <vector>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define BLOCK_SIZE 30



class Board {
        public:
        enum { POS_FREE = 0, POS_FILLED = 1 };

        Board(int screenW, int screenH);

        bool IsFreeBlock(int x, int y) const;
        void PrintBoard() const;
        void StorePiece(const Piece& piece);
        //void StorePiece(int pX, int pY, int pPiece, int pRotation);
        bool IsGameOver() const;
        void DeletePossibleLines();
        void DeleteLine(int py);
        void DebugFillLine(int y);
        bool IsPossibleMovement (const Piece& piece) const;

        int GetXPosInPixels(int x);
        int GetYPosInPixels(int y);

    private:
        int screenWidth;
        int screenHeight;
        void InitBoard();
        int mBoard[BOARD_HEIGHT][BOARD_WIDTH];
        std::array<Tetromino::Rotations, Tetromino::NUM_TYPE> allPieces;
};

#endif
