
#include "Game.hpp"



Game::Game(Board* pBoard, Tetromino* pPieces, IO* pIO, int pScreenHeight)
    : mBoard(pBoard), mIO(pIO), mScreenHeight(pScreenHeight),
      mCurrentPiece(0), mNextPiece(0)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int typeCurrent = rand() % 7;
    mCurrentPiece = Piece(typeCurrent);
    mCurrentPiece.SetPosition(BOARD_WIDTH / 2, 0);

    int typeNext = rand() % 7;
    mNextPiece = Piece(typeNext);
    mNextPiece.SetPosition(BOARD_WIDTH + 5, 5); 
}

void Game::CreateNewPiece()
{
    mCurrentPiece = mNextPiece;
    mCurrentPiece.SetPosition(BOARD_WIDTH / 2, 0);

    int typeNext = rand() % 7;
    mNextPiece = Piece(typeNext);
    mNextPiece.SetPosition(BOARD_WIDTH + 5, 5);
}