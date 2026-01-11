#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Piece.h"

// Forward declaration
class Board;


/**
 * @brief Abstract base class representing a game player.
 *
 * A Player has a name and an associated Piece, and defines the
 * interface for making a move on a Board.
 */
class Player {

protected:
    std::string name;
    Piece piece;

public:

    /**
    * @brief Constructs a player with a name and piece.
    * @param name The player's display name
    * @param piece The game piece controlled by the player
    */
    Player(const std::string& name, Piece piece) : name(name), piece(piece) {}

    virtual ~Player() = default; // virtual destructor for safe polymorphic deletion

    /**
 * @brief Performs a move on the given board.
 *
 * This is a pure virtual function that must be implemented
 * by derived player types (e.g., human or AI players).
 *
 * @param board The game board to modify
 * @return An integer indicating the result of the move
 *         (e.g., status code or move outcome)
 */
    virtual int makeMove(Board& board) = 0;

    /**
 * @brief Returns the player's name.
 * @return The name of the player
 */
    const std::string& getName() const { return name; }


    /**
 * @brief Returns the piece associated with this player.
 * @return The player's game piece
 */
    Piece getPiece() const { return piece; }
};

#endif
