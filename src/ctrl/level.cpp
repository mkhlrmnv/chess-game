#include "level.hpp"

#include "ctrl/pieces/pawn.hpp"


std::vector<std::vector<Square*>> Level::getGrid() const
{
    return grid;
}

void Level::printInfo()
{
    for (std::vector<Square*> row : grid)
    {
        for (Square* square : row)
        {
            square->printColor();
        }
        std::cout << std::endl;
    }
}

void Level::makeGrid()
{
    for (int i = 0; i < 8; i++) {
        std::vector<Square*> row;
        for (int j = 0; j < 8; j++)
        {
            row.push_back(new Square((i + j) % 2 == 0 ? Color::WHITE : Color::BLACK));
        }
        grid.push_back(row);
    }
}

void Level::reset()
{
    // Delete old grid
    for (std::vector<Square*> row : grid)
        {
            for (Square* square : row)
            {
                delete square;
            }
            row.clear();
        }
    grid.clear();

    // makes new one
    makeGrid();
}

std::vector<Piece*> Level::getPieces() const
{
    return pieces;
} 

bool Level::addPiece(Piece* piece)
{
    if (piece->getPosition().first < 0 || piece->getPosition().first > 7 || piece->getPosition().second < 0 || piece->getPosition().second > 7)
    {
        return false;
    }
    pieces.push_back(piece);
    grid[piece->getPosition().first][piece->getPosition().second]->setOccupied(piece->getColor() == 0 ? OccupiedBy::WHITE_PIECE : OccupiedBy::BLACK_PIECE);
    return true;
}

bool Level::addPieceByType(int type, std::pair<int, int> position) {
    switch (type)
    {
    case 0:
        return addPiece(new Pawn(*this, 0, 0, position));
        break;
    
    default:
        break;
    }
    return false;
}