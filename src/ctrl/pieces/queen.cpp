#include "queen.hpp"

Queen::Queen(Level& level, int type, int color, std::pair<int, int> position):
    Piece(level, 4, color, position) { }
