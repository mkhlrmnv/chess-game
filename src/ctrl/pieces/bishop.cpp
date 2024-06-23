#include "bishop.hpp"

Bishop::Bishop(Level& level, int type, int color, std::pair<int, int> position):
    Piece(level, 3, color, position) { }


bool Bishop::move() {
    std::cout << "moved" << std::endl;
    return true;
}