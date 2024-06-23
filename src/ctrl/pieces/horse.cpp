#include "horse.hpp"

Horse::Horse(Level& level, int type, int color, std::pair<int, int> position):
    Piece(level, 1, color, position) { }


bool Horse::move() {
    std::cout << "moved" << std::endl;
    return true;
}