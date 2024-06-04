#include "render.hpp"

Render::Render(){ }

void Render::drawLevel(sf::RenderWindow& rwindow) {
    rwindow.draw(_drawableLevel);
}

void Render::makeLevel(Level& level) {
    
    if (!_levelTexture.create(800, 800)) {
        std::cout << "RenderTexture creation failed for level" << std::endl;
    }

    std::vector<std::vector<Square *>> grid = level.getGrid();

    sf::RectangleShape square;

    int size = 100;

    int x = 0;
    int y = 0;

    for (auto column : grid){
        for (auto row : grid) {
            square.setSize(sf::Vector2f(size, size));
            square.setPosition(x * size, y * size);
            square.setFillColor(grid[x][y]->getColor() == Color::WHITE ? 
                sf::Color::White : sf::Color::Black);
            
            x++;
            square.setScale(2, 2);
            _levelTexture.draw(square);
        }
        x = 0;
        y++;
    }

    _levelTexture.display();
    _drawableLevel.setTexture(_levelTexture.getTexture());
}

