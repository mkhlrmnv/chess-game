#ifndef RENDER
#define RENDER

#include <SFML/Graphics.hpp>

#include "ctrl/level.hpp"

class Render{
private:

    sf::Sprite _drawableLevel;
    sf::RenderTexture _levelTexture;

    sf::Texture _blackSprite;
    sf::Texture _whiteSprite;     

public:

    Render();

    ~Render() { }

    void drawLevel(sf::RenderWindow& rwindow);
    void makeLevel(Level& level);

    void drawPiece(sf::RenderWindow& rwindow, Piece* piece);
    void drawPieces(sf::RenderWindow& rwindow, std::vector<Piece*> pieces);
};

#endif