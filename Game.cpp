
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
/*directly stores the piece in the board*/
void Game::StoreCurrentPiece()
{
    mBoard->StorePiece(mCurrentPiece);
}

void Game::DrawBoard ()
{
    // int mX1 = 0;  // left border
    // int mX2 = BOARD_WIDTH * BLOCK_SIZE;  // right border
    // int mY  = mScreenHeight - (BOARD_HEIGHT * BLOCK_SIZE);

    //window centered
    int mX1 = (mIO->GetScreenWidth() - (BOARD_WIDTH * BLOCK_SIZE)) / 2;
    int mX2 = mX1 + (BOARD_WIDTH * BLOCK_SIZE);
    int mY  = mScreenHeight - (BOARD_HEIGHT * BLOCK_SIZE);

    mIO->DrawRectangle(mX1 - BOARD_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
    mIO->DrawRectangle(mX2, mY, mX2 + BOARD_WIDTH, mScreenHeight - 1, BLUE);


    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            if (!mBoard->IsFreeBlock(i, j))
            {
                int x1 = mBoard->GetXPosInPixels(i);
                int y1 = mBoard->GetYPosInPixels(j);
                int x2 = x1 + BLOCK_SIZE - 1;
                int y2 = y1 + BLOCK_SIZE - 1;
                mIO->DrawRectangle(x1, y1, x2, y2, RED);

            }
        }
    }
}

void Game::DrawPiece(const Piece& piece)
{
    std::vector<std::pair<int, int>> blocks = piece.GetBlocks();


    for (int i = 0; i < (int)blocks.size(); ++i)
    {
        int bx = blocks[i].first;
        int by = blocks[i].second;


        int x1 = mBoard->GetXPosInPixels(bx);
        int y1 = mBoard->GetYPosInPixels(by);
        int x2 = x1 + BLOCK_SIZE - 1;
        int y2 = y1 + BLOCK_SIZE - 1;

        color c = GREEN;
        if (piece.IsPivot(bx, by))
            c = BLUE;


        mIO->DrawRectangle(x1, y1, x2, y2, c);
    }
}
void Game::DrawScene()
{
    mIO->ClearScreen();
    DrawBoard();
    DrawPiece(mCurrentPiece);
    DrawPiece(mNextPiece);
    mIO->UpdateScreen();
    
}


void Game::MoveLeft() {
    if (mBoard->IsPossibleMovement(mCurrentPiece))
        mCurrentPiece.MoveLeft();
}

void Game::MoveRight() {
    if (mBoard->IsPossibleMovement(mCurrentPiece))
        mCurrentPiece.MoveRight();
}

void Game::MoveDown() {
    if (mBoard->IsPossibleMovement(mCurrentPiece))
        mCurrentPiece.MoveDown();
}

void Game::RotatePiece() {
    mCurrentPiece.Rotate();
    if (!mBoard->IsPossibleMovement(mCurrentPiece)) {
        mCurrentPiece.RotateBack();
    }
}