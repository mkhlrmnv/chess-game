#include "level.hpp"

#include "ctrl/pieces/pawn.hpp"
#include "ctrl/pieces/horse.hpp"
#include "ctrl/pieces/rook.hpp"
#include "ctrl/pieces/bishop.hpp"
#include "ctrl/pieces/queen.hpp"
#include "ctrl/pieces/king.hpp"


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

    Square* sq = grid[piece->getPosition().first][piece->getPosition().second];
    sq->setOccupied(piece->getColor() == 0 ? OccupiedBy::WHITE_PIECE : OccupiedBy::BLACK_PIECE);
    sq->setPiece(piece);
    return true;
}

bool Level::addPieceByType(int type, std::pair<int, int> position, int color) {
    switch (type)
    {
    case 0:
        return addPiece(new Pawn(*this, type, color, position));
        break;
    case 1:
        return addPiece(new Horse(*this, type, color, position));
        break;
    case 2:
        return addPiece(new Rook(*this, type, color, position));
        break;
    case 3:
        return addPiece(new Bishop(*this, type, color, position));
        break;
    case 4:
        return addPiece(new Queen(*this, type, color, position));
        break;
    case 5:
        return addPiece(new King(*this, type, color, position));
        break;
    default:
        break;
    }
    return false;
}

bool Level::removePiece(Piece* piece){
    for (Piece* p : pieces){
        if (p == piece) {
            std::pair<int, int> pCords = p->getPosition();
            grid[pCords.first][pCords.second]->setOccupied(OccupiedBy::EMPTY);
            delete p;
            return true;
        }
    }
    return false;
}

bool Level::removePieceBySquare(std::pair<int, int> cords) {
    Square* sq = grid[cords.first][cords.second];
    Piece* piece = sq->getPiece();
    for (Piece* p : pieces) {
        if (p == piece) {
            delete p;
            sq->setOccupied(OccupiedBy::EMPTY);
            return true;
        }
    }
    return false;
}

Square* Level::getSquare(std::pair<int, int> cords) {
    return grid[cords.first][cords.second];
}

Piece* Level::getPieceByCords(std::pair<int, int> cords) {
    return grid[cords.first][cords.second]->getPiece();
}

Piece* Level::getPieceBySquare(Square* square) {
    return square->getPiece();
}