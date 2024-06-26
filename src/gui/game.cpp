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

        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
            // Convert mousePos to chess board coordinates and store in selectedPiecePosition
            // You need to implement convertMousePosToChessBoard method
            selectedPiecePosition = converMousePosToChessBoard(mousePos);
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            std::cout << "mouse button released" << std::endl;
            sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
            // Convert mousePos to chess board coordinates
            sf::Vector2i newPiecePosition = converMousePosToChessBoard(mousePos);
            // Move the selected piece to the new position
            // You need to implement movePiece method
            movePiece(selectedPiecePosition, newPiecePosition);
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

sf::Vector2i Game::converMousePosToChessBoard(sf::Vector2i mousePos) {
    // Assuming each square on the chess board is 60x60 pixels
    int squareSize = 100;
    int x = mousePos.x / squareSize;
    int y = mousePos.y / squareSize;
    return sf::Vector2i(x, y);
}

void Game::movePiece(sf::Vector2i selectedPos, sf::Vector2i newPos) {
    std::vector<std::vector<Square*>> grid = _level.getGrid();
    Square* oldSq = grid[selectedPos.x][selectedPos.y];
    Square* newSq = grid[newPos.x][newPos.y];
    Piece* p = oldSq->getPiece();
    oldSq->setOccupied(OccupiedBy::EMPTY);

    if (p->getColor() == Color::BLACK) {
        newSq->setOccupied(OccupiedBy::BLACK_PIECE);
    } else {
        newSq->setOccupied(OccupiedBy::WHITE_PIECE);
    }

    newSq->setPiece(p);
    
    p->move(std::make_pair(newPos.x, newPos.y));
}

void Game::run(){
    openWindow();
 
    _level.addPieceByType(0, std::make_pair(3, 3), 0);

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