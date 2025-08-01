#ifndef GAME_HPP
#define GAME_HPP

#include "Tetromino.hpp"
#include "Board.hpp"
#include "Piece.hpp"

class Game {
    public:

        Game (Board *pBoard, Tetromino *pPieces, IO *pIO, int pScreenHeight);

        void DrawScene ();
        void CreateNewPiece ();

    private:

        int mPosX, mPosY;
        Piece mCurrentPiece;
        Piece mNextPiece;
        Board *mBoard;

        IO *mIO;
        int mScreenHeight;

        // int GetRand (int pA, int pB);
        // void InitGame();
        // void DrawPiece (int pX, int pY, int pPiece, int pRotation);
        // void DrawBoard ();
};

#endif



