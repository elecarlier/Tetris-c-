#include <iostream>
#include "Tetromino.hpp"
#include "Board.hpp"

void printShape(const Tetromino::Shape& shape) {
    for (int i = 0; i < Tetromino::SIZE; ++i) {
        for (int j = 0; j < Tetromino::SIZE; ++j)
            std::cout << shape[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "----------------\n";
}

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

int main() {
    Board board;

    // Place une pièce T (type = 6), rotation = 0, en (4, 0)
   //board.PrintBoard();
    board.StorePiece(4, 3, 6, 0);

    board.PrintBoard();

    return 0;
}