#ifndef Lelel_hpp
#define Level_hpp

#include <vector>


class Level
{
private:
    std::vector<std::vector<Square>> grid;
    std::vector<Pieces> blackPieces;
    std::vector<Pieces> whitePieces;

public:
    Level();
    ~Level();
};



#endif