#ifndef Piece_hpp
#define Piece_hpp

#include <utility>
#include <iostream>
#include <vector>

// Pre defenition of level, that is redifined later
class Level;

enum Type {
    NONE,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

class Piece {
private:
    int type;
    int color;
    std::pair<int, int> position;
    std::vector<std::pair<int, int>> possibleMoves;
    Level& level;

public:
    Piece(Level& level, int type, int color, std::pair<int, int> position);
    ~Piece();

    int getType() const;   
    int getColor() const;
    std::pair<int, int> getPosition() const;
    std::vector<std::pair<int, int>> getPossibleMoves() const;

    void printInfo();
};

#endif