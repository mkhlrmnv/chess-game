#ifndef GAME
#define GAME

// #include "level.hpp"
#include "render.hpp"

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

    Render _render;

public:
    Game();

    ~Game() { }

    void run();

    bool checkIfMate();

    State getState() const;
    void setState(State state);
};

#endif