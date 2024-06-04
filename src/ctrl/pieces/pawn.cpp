#include "pawn.hpp"

Pawn::Pawn(Level& level, int type, int color, std::pair<int, int> position):
    Piece(level, 1, color, position) { }


bool Pawn::move() {
    std::cout << "moved" << std::endl;
    return true;
}