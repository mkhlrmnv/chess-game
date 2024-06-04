#include <iostream>

// #include "level.hpp"
#include "gui/game.hpp"

int main() {
    /*
    Level level;
    Piece piece(level, 0, 0, std::make_pair(3, 3));
    level.addPiece(&piece);
    level.printInfo();
    */

    Game game;
    game.run();

    return 0;
}