
#include "Game.hpp"



Game::Game(Board* pBoard, Tetromino* pPieces, IO* pIO, int pScreenHeight)
    : mBoard(pBoard), mIO(pIO), mScreenHeight(pScreenHeight),
      mCurrentPiece(0), mNextPiece(0)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int typeCurrent = rand() % 7;
    mCurrentPiece = Piece(typeCurrent);
    mCurrentPiece.SetPosition(BOARD_WIDTH / 2 - 2 , 4);

    int typeNext = rand() % 7;
    mNextPiece = Piece(typeNext);
    mNextPiece.SetPosition(0, 0);
}

void Game::CreateNewPiece()
{
    mCurrentPiece = mNextPiece;
    mCurrentPiece.SetPosition(BOARD_WIDTH / 2 - 2, 4);

    int typeNext = rand() % 7;
    mNextPiece = Piece(typeNext);
    mNextPiece.SetPosition(0, 0);
}
/*directly stores the piece in the board*/
void Game::StoreCurrentPiece()
{
    mBoard->StorePiece(mCurrentPiece);
}

void Game::DrawBoard ()
{
    int mX1 = mBoard->GetXPosInPixels(0);               
    int mX2 = mBoard->GetXPosInPixels(BOARD_WIDTH);

   int mY  = mScreenHeight - (BOARD_HEIGHT * BLOCK_SIZE);
   
    mIO->DrawRectangle(mX1 - 1, mY, mX1, mScreenHeight - 1, BLUE);
    mIO->DrawRectangle(mX2, mY, mX2 + 1, mScreenHeight - 1, BLUE);

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

void Game::DrawPiece(const Piece& piece, bool isNext)
{
    std::vector<std::pair<int, int>> blocks = piece.GetBlocks();

    int offsetX = 0;
    int offsetY = 0;

    if (isNext) {
        int boardRight = mBoard->GetXPosInPixels(BOARD_WIDTH);
        offsetX = boardRight + 50;
        offsetY = 50;   
    }

    for (int i = 0; i < (int)blocks.size(); ++i)
    {
        int bx = blocks[i].first;
        int by = blocks[i].second;

        int x1, y1;
        if (isNext) {
            x1 = bx * BLOCK_SIZE + offsetX;
            y1 = by * BLOCK_SIZE + offsetY;
        } else {
            x1 = mBoard->GetXPosInPixels(bx);
            y1 = mBoard->GetYPosInPixels(by);
        }

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
    DrawPiece(mCurrentPiece, false);
    DrawPiece(mNextPiece, true);  
    mIO->UpdateScreen();
    
}


void Game::MoveLeft() {
    mCurrentPiece.MoveLeft();
    if (!mBoard->IsPossibleMovement(mCurrentPiece))
        mCurrentPiece.MoveRight();
        
}

void Game::MoveRight() {
    mCurrentPiece.MoveRight();
    if (!mBoard->IsPossibleMovement(mCurrentPiece))
        mCurrentPiece.MoveLeft();
}

void Game::MoveDown() {
    mCurrentPiece.MoveDown();
    if (!mBoard->IsPossibleMovement(mCurrentPiece)) {
        mCurrentPiece.MoveUp();
        StoreCurrentPiece();        
        mBoard->DeletePossibleLines(); 
        if (mBoard->IsGameOver()) {
            std::cout << "Game Over!" << std::endl;
            exit(0);
        }
        CreateNewPiece();
    }
}

void Game::RotatePiece() {
    mCurrentPiece.Rotate();
    if (!mBoard->IsPossibleMovement(mCurrentPiece)) {
        mCurrentPiece.RotateBack();
    }
}

// void Game::FallDown()
// {
//     while(mBoard->IsPossibleMovement(mCurrentPiece))
//     {
//         mCurrentPiece.MoveDown();
//         if (!mBoard->IsPossibleMovement(mCurrentPiece))
//         {
//             mCurrentPiece.MoveUp();
//             break;
//         }
//         DrawScene();
//     }
        
// }

void Game::FallDown() {
    
    while (mBoard->IsPossibleMovement(mCurrentPiece)) 
        mCurrentPiece.MoveDown();
    mCurrentPiece.MoveUp();
    StoreCurrentPiece();        
    mBoard->DeletePossibleLines(); 
    if (mBoard->IsGameOver()) {
        std::cout << "Game Over!" << std::endl;
        exit(0);
    }
    CreateNewPiece();

}