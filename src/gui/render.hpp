#ifndef RENDER
#define RENDER

#include <SFML/Graphics.hpp>
#include <memory>

#include "ctrl/level.hpp"

class Render{
private:

    sf::Sprite _drawableLevel;
    sf::RenderTexture _levelTexture;

    std::shared_ptr<sf::Texture> _blackSprite;
    std::shared_ptr<sf::Texture> _whiteSprite;   

    std::shared_ptr<sf::Texture> _currentSprite;
    sf::Sprite _drawableTexture;

public:

    Render();

    ~Render() { }

    void drawLevel(sf::RenderWindow& rwindow);
    void makeLevel(Level& level);

    void drawPiece(sf::RenderWindow& rwindow, Piece* piece);
    void drawPieces(sf::RenderWindow& rwindow, std::vector<Piece*> pieces);

    void loadTexture();
    

};

#endif