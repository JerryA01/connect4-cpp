#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include <memory>

/**
 * @brief Controls the main game flow.
 *
 * The Game class manages the board and alternates turns
 * between two players until the game ends.
 */
class Game {
private:
    Board board;
    Player& player1;
    Player& player2;
    bool gameOver = false;


public:
    /**
       * @brief Constructs a game with two players.
       *
       * The Game does not take ownership of the player objects.
       *
       * @param p1 Pointer to the first player
       * @param p2 Pointer to the second player
       */
    Game(Player& p1, Player& p2);

    /**
    * @brief Starts the main game loop.
    *
    * Alternates turns between players until the game ends.
    */
    void start();
    void endGame();
};

#endif