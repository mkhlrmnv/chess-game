#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "ctrl/piece.hpp"

class Queen: public Piece {
private:


public:

    Queen(Level& level, int type, int color, std::pair<int, int> position);

    ~Queen() { }

    bool move();
};

#endif