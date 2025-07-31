#include <iostream>
#include "Tetromino.hpp"

void printShape(const Tetromino::Shape& shape) {
    for (int i = 0; i < Tetromino::SIZE; ++i) {
        for (int j = 0; j < Tetromino::SIZE; ++j)
            std::cout << shape[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "----------------\n";
}

int main() {
    auto rotations = Tetromino::generateShape(6); // test avec le T par exemple

    for (int i = 0; i < Tetromino::NUM_ROT; ++i) {
        std::cout << "Rotation " << i << ":\n";
        printShape(rotations[i]);
    }

    return 0;
}
