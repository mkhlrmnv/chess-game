#ifndef Lelel_hpp
#define Level_hpp

// Libraries
#include <vector>
#include <utility> // std::pair

// Other classes
#include "square.hpp"

class Level
{
private:
    std::vector<std::vector<Square*>> grid;

public:
    Level();
    ~Level();

    std::vector<std::vector<Square*>> getGrid() const;

    void printInfo();

    void makeLevel();

};



#endif