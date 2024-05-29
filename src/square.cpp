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