#ifndef GAME_HPP
#define GAME_HPP

#include "IO.h"
#include <time.h>
#include <cstdlib>

#include "Tetromino.hpp"
#include "Board.hpp"
#include "Piece.hpp"

#define WAIT_TIME 700 // Number of milliseconds that the piece remains before going 1 block down

class Game {
    public:

        Game (Board *pBoard, Tetromino *pPieces, IO *pIO, int pScreenHeight);

        void DrawScene ();
        void CreateNewPiece ();

        void MoveLeft();
        void MoveRight();
        void MoveDown();
        void RotatePiece();

    private:

        //int mPosX, mPosY;
        Piece mCurrentPiece;
        Piece mNextPiece;

        Tetromino* mPieces;
        Board *mBoard;

        IO *mIO;
        int mScreenHeight;

        int GetRand(int a, int b);
        // int GetRand (int pA, int pB);
        // void InitGame();
        // void DrawPiece (int pX, int pY, int pPiece, int pRotation);
        void DrawBoard ();
};

#endif



