#ifndef HORSE_HPP
#define HORSE_HPP

#include "ctrl/piece.hpp"

class Horse: public Piece {
private:


public:

    Horse(Level& level, int type, int color, std::pair<int, int> position);

    ~Horse() { }

    bool move();
};

#endif