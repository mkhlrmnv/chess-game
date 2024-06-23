#include "rook.hpp"

Rook::Rook(Level& level, int type, int color, std::pair<int, int> position):
    Piece(level, 2, color, position) { }
