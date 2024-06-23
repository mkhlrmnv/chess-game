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

void Game::pollEvents(){
    sf::Event event;

    while (_window.pollEvent(event)){
        if (event.type == sf::Event::Closed) {
            _window.close();
            return;
        }
        _render.makeLevel(_level);
    }
}

void Game::render(){
    _window.clear();
    _render.drawLevel(_window);
    _render.drawPieces(_window, _level.getPieces());
    _window.display();
}

void Game::run(){
    openWindow();
 
    _level.addPieceByType(0, std::make_pair(3, 3));

    while (_window.isOpen()){
        pollEvents();
        render();
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