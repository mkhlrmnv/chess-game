#include "piece.hpp"
#include "level.hpp"

Piece::Piece(Level& level, int type, int color, std::pair<int, int> position):
    level(level),
    type(type),
    color(color),
    position(position) { }

Piece::~Piece() { }

int Piece::getType() const {
    return type;
}

int Piece::getColor() const {
    return color;
}

std::pair<int, int> Piece::getPosition() const {
    return position;
}

std::vector<std::pair<int, int>> Piece::getPossibleMoves() const {
    return possibleMoves;
}

void Piece::printInfo() {
    std::cout << "P" << std::ends;
}

bool Piece::move(std::pair<int, int> whereTo) { 
    position = whereTo;
    
    return true;
    /*
    for (auto sq : possibleMoves) {
        if (sq == whereTo) {
            position = whereTo;
            return true;
        }
    }
    return false;
    */
}