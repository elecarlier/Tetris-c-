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
        void RotateBack();

        int GetX() const;
        int GetY() const;
        int GetRotation() const;
        int GetType() const;

        void SetPosition(int newX, int newY);
        void SetRotation(int r);

        // Renvoie les blocs occupés par la pièce sous forme de coordonnées (x, y)
        std::vector<std::pair<int, int>> GetBlocks() const;
        bool IsPivot(int blockX, int blockY) const;

    private:
        int type;       //  0..6
        int rotation;   // 0..3
        int x, y;       // pivot

        static const int pivot_i = 2;
        static const int pivot_j = 2;
};

#endif
