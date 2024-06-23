#ifndef ROOK_HPP
#define ROOK_HPP

#include "ctrl/piece.hpp"

class Rook: public Piece {
private:


public:

    Rook(Level& level, int type, int color, std::pair<int, int> position);

    ~Rook() { }

};

#endif