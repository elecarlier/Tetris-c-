#include "IO.hpp"
#include <iostream>

IO::IO() : window(NULL), renderer(NULL), screenWidth(0), screenHeight(0) {}

IO::~IO() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window)   SDL_DestroyWindow(window);
    SDL_Quit();
}

int IO::InitGraph(int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init error: " << SDL_GetError() << "\n";
        return 1;
    }

    window = SDL_CreateWindow("Tetris",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height,
                              SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << "\n";
        return 2;
    }

    renderer = SDL_CreateRenderer(window, -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << "\n";
        return 3;
    }

    screenWidth  = width;
    screenHeight = height;
    return 0;
}

void IO::ClearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void IO::UpdateScreen() {
    SDL_RenderPresent(renderer);
}

int IO::GetScreenHeight() const {
    return screenHeight;
}

int IO::GetScreenWidth() const {
    return screenWidth;
}


void IO::setDrawColor(enum color c) {
    switch (c) {
        case BLACK:   SDL_SetRenderDrawColor(renderer, 0,   0,   0,   255); break;
        case RED:     SDL_SetRenderDrawColor(renderer, 255, 0,   0,   255); break;
        case GREEN:   SDL_SetRenderDrawColor(renderer, 0,   255, 0,   255); break;
        case BLUE:    SDL_SetRenderDrawColor(renderer, 0,   0,   255, 255); break;
        case CYAN:    SDL_SetRenderDrawColor(renderer, 0,   255, 255, 255); break;
        case MAGENTA: SDL_SetRenderDrawColor(renderer, 255, 0,   255, 255); break;
        case YELLOW:  SDL_SetRenderDrawColor(renderer, 255, 255, 0,   255); break;
        case WHITE:   SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); break;
        default:      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); break;
    }
}

/*
x1,y1: up left
x2, y2: up right

SDL_Rect uses up left as starting point x and y
*/
void IO::DrawRectangle(int x1, int y1, int x2, int y2, enum color c) {
    if (!renderer) return;
    setDrawColor(c);
    SDL_Rect r;
    r.x = x1;
    r.y = y1;
    r.w = (x2 - x1 + 1);
    r.h = (y2 - y1 + 1);
    if (r.w < 0) { r.x += r.w; r.w = -r.w; }
    if (r.h < 0) { r.y += r.h; r.h = -r.h; }
    SDL_RenderFillRect(renderer, &r);
}

int IO::Pollkey() 
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return SDLK_ESCAPE; // on utilise ESC pour signaler quitter
        }
        if (e.type == SDL_KEYDOWN) {
            return e.key.keysym.sym; // SDL_Keycode
        }
    }
    return -1;
}

int IO::IsKeyDown(int key) 
{
    SDL_PumpEvents();
    const Uint8* state = SDL_GetKeyboardState(NULL);
    SDL_Scancode sc = SDL_GetScancodeFromKey(key);
    return state[sc] ? 1 : 0;
}
