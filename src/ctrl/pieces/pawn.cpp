#include "pawn.hpp"

Pawn::Pawn(Level& level, int type, int color, std::pair<int, int> position):
    Piece(level, 0, color, position) { }

