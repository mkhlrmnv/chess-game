#include "square.hpp"

Square::Square(Color color):
    occupied(EMPTY),
    color(color) { }

OccupiedBy Square::getOccupied() const {
    return occupied;
}

void Square::setOccupied(OccupiedBy occupied) {
    this->occupied = occupied;
}

Color Square::getColor() const {
    return color;
}

void Square::printInfo() {
    std::cout << "Occupied by: " << occupied << std::endl;
    std::cout << "Color: " << color << std::endl;
}

void Square::printColor() {

    if (occupied == OccupiedBy::EMPTY) {   
        switch (color) {
            case Color::WHITE:
                std::cout << "W" << std::ends;
                break;
            case Color::BLACK:
                std::cout << "B" << std::ends;
                break;
            default:
                break;
        }
    } else {
        std::cout << "P" << std::ends;
    }
}

Piece* Square::getPiece() {
    return piece;
}

void Square::setPiece(Piece* p) {
    piece = p;
}