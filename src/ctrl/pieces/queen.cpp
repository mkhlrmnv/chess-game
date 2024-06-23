#include "queen.hpp"

Queen::Queen(Level& level, int type, int color, std::pair<int, int> position):
    Piece(level, 4, color, position) { }


bool Queen::move() {
    std::cout << "moved" << std::endl;
    return true;
}