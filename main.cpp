// #include <iostream>
// #include "Tetromino.hpp"
// #include "Board.hpp"

// void printShape(const Tetromino::Shape& shape) {
//     for (int i = 0; i < Tetromino::SIZE; ++i) {
//         for (int j = 0; j < Tetromino::SIZE; ++j)
//             std::cout << shape[i][j] << " ";
//         std::cout << "\n";
//     }
//     std::cout << "----------------\n";
// }

// int main() {

//     Board board;
//     board.PrintBoard();
//     auto allPieces = Tetromino::generateAll();

//     return 0;
//     // auto rotations = Tetromino::generateShape(6); // test avec le T par exemple

//     // for (int i = 0; i < Tetromino::NUM_ROT; ++i) {
//     //     std::cout << "Rotation " << i << ":\n";
//     //     printShape(rotations[i]);
//     // }

//     return 0;
// }



// int main() {
//     Board board;

//     board.DebugFillLine(19);
//     std::cout << "Avant suppression :\n";
//     board.PrintBoard();
//     std::cout << "----------------\n";

//     board.DeletePossibleLines();

//     std::cout << "Après suppression :\n";
//     board.PrintBoard();
//     std::cout << "----------------\n";

//     return 0;
// }

#include "IO.hpp"

// int main() {
//     IO io;
//     if (io.InitGraph(640, 480) != 0) return 1;

//     io.ClearScreen();
//     // rect 200x100 centré
//     int cx = 320, cy = 240;
//     int w = 200, h = 100;
//     io.DrawRectangle(cx - w/2, cy - h/2, cx + w/2, cy + h/2, RED);
//     io.UpdateScreen();

//     SDL_Delay(1500);
//     return 0;
// }

// int main() {
//     IO io;
//     if (io.InitGraph(640, 480) != 0) return 1;

//     bool running = true;
//     int x = 300, y = 220;

//     while (running) {
//         int key = io.Pollkey();
//         if (key == SDLK_ESCAPE) running = false;

//         if (io.IsKeyDown(SDLK_LEFT))  x -= 4;
//         if (io.IsKeyDown(SDLK_RIGHT)) x += 4;
//         if (io.IsKeyDown(SDLK_UP))    y -= 4;
//         if (io.IsKeyDown(SDLK_DOWN))  y += 4;

//         io.ClearScreen();
//         io.DrawRectangle(x, y, x+40, y+40, GREEN);
//         io.UpdateScreen();

//         SDL_Delay(16); // ~60 FPS
//     }
//     return 0;
// }


#include "Game.hpp"
#include "Board.hpp"
#include "Piece.hpp"
#include "IO.hpp"
#include <iostream>
#include <chrono>
#include <thread>

#define BLOCK_SIZE 30

#include "Game.hpp"
#include "Board.hpp"
#include "Piece.hpp"
#include "IO.hpp"
#include "Tetromino.hpp"
#include <iostream>
#include <chrono>
#include <thread>

#define BLOCK_SIZE 30

int main() {
    IO io;

    if (io.InitGraph(640, 480) != 0) {
        std::cerr << "Failed to initialize graphics\n";
        return 1;
    }

    Board board;         
    Tetromino tetromino;  
    Game game(&board, &tetromino, &io, 480); 
    bool running = true;

    while (running) {
        game.DrawScene();

        int key = io.Pollkey();
        if (key != -1) {
            if (key == SDLK_ESCAPE) {
                running = false;
            } else if (key == SDLK_LEFT) {
                game.MoveLeft();
            } else if (key == SDLK_RIGHT) {
                game.MoveRight();
            } else if (key == SDLK_DOWN) {
                game.MoveDown();
            } else if (key == SDLK_UP) {
                game.RotatePiece();
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
