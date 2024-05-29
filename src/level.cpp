#include "level.hpp"


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