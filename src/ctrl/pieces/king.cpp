#include "king.hpp"

King::King(Level& level, int type, int color, std::pair<int, int> position):
    Piece(level, 0, color, position) { }


bool King::move() {
    std::cout << "moved" << std::endl;
    return true;
}