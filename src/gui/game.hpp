#ifndef GAME
#define GAME

// #include "level.hpp"
#include "render.hpp"
#include "ctrl/pieces/pawn.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



enum State {
    PLAYING,
    CHECK,
    CHECK_MATE
};

class Game {
private:
    Level _level;
    State _state;
    sf::RenderWindow _window;

    int _resolution;

    void update();
    void render();
    void openWindow();
    void pollEvents();

    sf::Vector2i converMousePosToChessBoard(sf::Vector2i mousePos);
    void movePiece(sf::Vector2i selectedPos, sf::Vector2i newPos);

    Render _render;

public:
    Game();

    ~Game() { }

    void run();

    bool checkIfMate();

    State getState() const;
    void setState(State state);

    sf::Vector2i selectedPiecePosition;
};

#endif