#include "rook.hpp"

Rook::Rook(Level& level, int type, int color, std::pair<int, int> position):
    Piece(level, 0, color, position) { }


bool Rook::move() {
    std::cout << "moved" << std::endl;
    return true;
}