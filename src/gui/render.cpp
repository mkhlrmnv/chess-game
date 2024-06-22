#include "render.hpp"

Render::Render(){ 
    loadTexture();
}

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

void Render::drawPiece(sf::RenderWindow& rwindow, Piece* piece) {
    int type = piece->getType();
    int color = piece->getColor();

    switch (color)
    {
    case 0:
        _currentSprite = _whiteSprite;
        break;
    default:
        _currentSprite = _blackSprite;
        break;
    }

    _drawableTexture.setTexture(*_currentSprite);

    switch (type)
    {
    case 1:
        _drawableTexture.setTextureRect(sf::IntRect(0, 0, 16, 16));
        std::cout << "draw one pawn" << std::endl;
        break;
    default:
        break;
    }
    _drawableTexture.setScale(7, 7);
    _drawableTexture.setPosition(sf::Vector2f(93, 80));
    rwindow.draw(_drawableTexture);
}

void Render::drawPieces(sf::RenderWindow& rwindow, std::vector<Piece*> pieces) {
    for (Piece* p : pieces) {
        this->drawPiece(rwindow, p);
    }
}

void Render::loadTexture() {
    // loads balck sprite
    std::shared_ptr<sf::Texture> blackTx = std::make_shared<sf::Texture>();
    blackTx->loadFromFile("../assets/pixel chess/16x16 pieces/BlackPieces.png");
    _blackSprite = blackTx;

    std::shared_ptr<sf::Texture> whiteTx = std::make_shared<sf::Texture>();
    whiteTx->loadFromFile("../assets/pixel chess/16x16 pieces/WhitePieces.png");
    _whiteSprite = whiteTx;
}