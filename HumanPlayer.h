#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Board.h"

class HumanPlayer : public Player {
public:
    /**
 * @brief Represents a human-controlled player.
 *
 * A HumanPlayer prompts the user for input and performs
 * moves based on user interaction.
 */
    HumanPlayer(const std::string& name, Piece piece);

    /**
 * @brief Prompts the user to make a move on the board.
 *
 * @param board The board on which the move is made
 * @return An integer indicating the result of the move
 */
    int makeMove(Board& board) override;
};

#endif
