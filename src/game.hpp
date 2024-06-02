#ifndef GAME
#define GAME

#include "level.hpp"


enum State {
    PLAYING,
    CHECK,
    CHECK_MATE
};

class Game {
private:
    Level* _level;
    State _state;

    void update();
    void render();

    // TODO: Un comment when implemented
    // Renderer _renderer;
    // sf::RenderWindow _window;
    


public:
    Game();

    ~Game() { delete _level; }

    void run();

    bool checkIfMate();

    State getState() const;
    void setState(State state);
};

#endif