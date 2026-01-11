#include "Game.h"
#include "HumanPlayer.h"
#include <memory>


int main() {
    auto firstPlayer  = std::make_unique<HumanPlayer>("Alice", Piece::X);
    auto secondPlayer = std::make_unique<HumanPlayer>("Bob", Piece::O);

    Game game(*firstPlayer, *secondPlayer);
    game.start();

    return 0;
}

