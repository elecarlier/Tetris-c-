
#include "Game.hpp"
#include "Board.hpp"
#include "Piece.hpp"
#include "IO.hpp"
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

    Board board(io.GetScreenWidth(), io.GetScreenHeight());
    Tetromino tetromino;
    Game game(&board, &tetromino, &io, io.GetScreenHeight());
    unsigned long lastTick = SDL_GetTicks();

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
            } else if (key == SDLK_z) {
                game.RotatePiece();
            } else if (key == SDLK_x) {
                game.FallDown();
            }
        }

        unsigned long now = SDL_GetTicks();
        if ((now - lastTick) > WAIT_TIME) {
            game.MoveDown();  
            lastTick = now;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }


    return 0;
}
