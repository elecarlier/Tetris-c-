#ifndef PIECE_HPP
#define PIECE_HPP

#include "Tetromino.hpp"

class Piece {
    public:
        Piece(int type);

        void MoveLeft();
        void MoveRight();
        void MoveDown();
        void Rotate();

        int GetX() const;
        int GetY() const;
        int GetRotation() const;
        int GetType() const;

        void SetPosition(int newX, int newY);
        void SetRotation(int rotation);

        // Renvoie les blocs occupés par la pièce sous forme de coordonnées (x, y)
        std::vector<std::pair<int, int>> GetBlocks() const;

    private:
        int type;       // Type de pièce : 0 à 6
        int rotation;   // Rotation actuelle : 0 à 3
        int x, y;       // Position du pivot dans le board

        static const int pivot_i = 2;
        static const int pivot_j = 2;
};

#endif
