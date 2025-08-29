#ifndef GAME_HPP
#define GAME_HPP

#include "IO.hpp"
#include <ctime>
#include <cstdlib>

#include "Tetromino.hpp"
#include "Board.hpp"
#include "Piece.hpp"

#define WAIT_TIME 500 // Number of milliseconds that the piece remains before going 1 block down

class Game {
    public:

        Game (Board *pBoard, Tetromino *pPieces, IO *pIO, int pScreenHeight);

        void DrawScene ();
        void CreateNewPiece ();
        void DrawPiece(const Piece& piece, bool isNext);

        void MoveLeft();
        void MoveRight();
        void MoveDown();
        void RotatePiece();
        void FallDown();


    private:

        //int mPosX, mPosY;
        Piece mCurrentPiece;
        Piece mNextPiece;

        Tetromino* mPieces;
        Board *mBoard;

        IO *mIO;
        int mScreenHeight;

        int GetRand(int a, int b);
        void DrawBoard ();
        void StoreCurrentPiece();
};

#endif



