#ifndef Lelel_hpp
#define Level_hpp

// Libraries
#include <vector>
#include <utility> // std::pair

// Other classes
#include "square.hpp"
#include "piece.hpp"

class Level
{
private:
    std::vector<std::vector<Square*>> grid;
    std::vector<Piece*> pieces;

public:
    Level() { makeGrid(); }

    ~Level() { 
        for (std::vector<Square*> row : grid)
        {
            for (Square* square : row)
            {
                delete square;
            }
            row.clear();
        }
        grid.clear();
    };

    std::vector<std::vector<Square*>> getGrid() const;

    void printInfo();

    void makeGrid();

    void reset();

    std::vector<Piece*> getPieces() const;
    bool addPiece(Piece* piece);

    bool addPieceByType(int type, std::pair<int, int> position);
};



#endif