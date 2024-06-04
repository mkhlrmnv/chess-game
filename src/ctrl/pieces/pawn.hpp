#ifndef PAWN_HPP
#define PAWN_HPP

#include "ctrl/piece.hpp"

class Pawn: public Piece {
private:


public:

    Pawn(Level& level, int type, int color, std::pair<int, int> position);

    ~Pawn() { }

    bool move();
};



#endif