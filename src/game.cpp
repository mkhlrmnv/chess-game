#include "game.hpp"

Game::Game():
    _level(),
    _state(State::PLAYING),
    _window(),
    _resolution(800)
{ }

void Game::openWindow(){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    settings.depthBits = 24;
    settings.stencilBits = 8;

    _window.create(sf::VideoMode(_resolution, _resolution), "Chess", 
        sf::Style::Default, settings);
    _window.setPosition(sf::Vector2i(200, 0));
    _window.setVerticalSyncEnabled(true);
}

void Game::run(){
    openWindow();

    while (_window.isOpen()){
        
    }
}

State Game::getState() const
{
    return _state;
}

void Game::setState(State state)
{
    _state = state;
}