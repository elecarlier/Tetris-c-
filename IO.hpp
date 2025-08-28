
#ifndef IO_HPP
#define IO_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


enum color { BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX };

class IO {
    public:
        IO();
        ~IO();

        int InitGraph(int width = 640, int height = 480);
        void ClearScreen();
        void DrawRectangle(int x1, int y1, int x2, int y2, enum color c);
        void UpdateScreen();

        int GetScreenHeight() const;
        int GetScreenWidth() const;

        int Pollkey();
        int IsKeyDown(int key);
        void setDrawColor(enum color c);

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        int screenWidth, screenHeight;
        Uint32 mColors[COLOR_MAX];
};

#endif