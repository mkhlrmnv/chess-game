#include "game.hpp"

Game::Game()
{
    _level = new Level();
    _state = PLAYING;
}

State Game::getState() const
{
    return _state;
}

void Game::setState(State state)
{
    _state = state;
}