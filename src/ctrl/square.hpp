#ifndef Square_hpp
#define Square_hpp

#include <vector>
#include <iostream>

enum OccupiedBy {
    EMPTY,
    WHITE_PIECE,
    BLACK_PIECE
};

enum Color {
    WHITE,
    BLACK
};

class Square {
private:  
    OccupiedBy occupied;
    Color color;

public:
    Square(Color color);
    ~Square() { } 

    OccupiedBy getOccupied() const;
    
    void setOccupied(OccupiedBy occupied);
    
    Color getColor() const;
    
    void printInfo();

    void printColor();
};


#endif