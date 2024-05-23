#ifndef Square_hpp
#define Square_hpp

#include <vector>

enum OccupiedBy {
    EMPTY,
    WHITE,
    BLACK
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

};


#endif