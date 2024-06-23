#ifndef KING_HPP
#define KING_HPP

#include "ctrl/piece.hpp"

class King: public Piece {
private:


public:

    King(Level& level, int type, int color, std::pair<int, int> position);

    ~King() { }

    bool move();
};

#endif