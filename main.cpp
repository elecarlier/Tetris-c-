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

    board.DebugFillLine(19);
    std::cout << "Avant suppression :\n";
    board.PrintBoard();
    std::cout << "----------------\n";

    board.DeletePossibleLines();

    std::cout << "Après suppression :\n";
    board.PrintBoard();
    std::cout << "----------------\n";

    return 0;
}
