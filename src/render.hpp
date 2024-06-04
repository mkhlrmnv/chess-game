#ifndef RENDER
#define RENDER

#include <SFML/Graphics.hpp>

#include "level.hpp"

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
};

#endif