#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "ctrl/piece.hpp"

class Bishop: public Piece {
private:


public:

    Bishop(Level& level, int type, int color, std::pair<int, int> position);

    ~Bishop() { }

    bool move();
};



#endif