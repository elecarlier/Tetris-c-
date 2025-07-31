#ifndef TETROMINO_HPP
#define TETROMINO_HPP

#include <array>


class Tetromino {
    public: 
        static const int SIZE = 5;
        static const int NUM_ROT = 4;
        static const int NUM_TYPE = 7;

        using Shape = std::array<std::array<int,SIZE>, SIZE>;
        using Rotations = std::array<Shape, NUM_ROT>;

        Tetromino();
        static std::array<Rotations, NUM_TYPE> generateAll();
        //int blocks[7][4][SIZE][SIZE];
        static Rotations generateShape(int type); // Génère une forme avec ses rotations
    private:
        
        static Shape rotate(const Shape& shape);  // Retourne la rotation d'une shape
};

#endif