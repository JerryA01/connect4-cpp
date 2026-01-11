#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>

/**
 * @brief Represents the game board and its state.
 *
 * The Board manages a 2D grid of pieces and provides
 * operations for placing pieces, validating moves,
 * checking win conditions, and applying special abilities.
 */
class Board {
private:
    static const int ROWS = 6;  ///< Number of board rows
    static const int COLS = 7; ///< Number of board columns
    std::vector<std::vector<Piece>> grid; ///< Board grid

public:
    /**
    * @brief Constructs an empty board.
    */
    Board();

    /**
 * @brief Attempts to drop a piece into the given column.
 *
 * The piece will occupy the lowest available row in the column.
 *
 * @param column Zero-based column index
 * @param piece The piece to drop
 * @return true if the piece was placed successfully, false otherwise
 */
    bool dropPiece(int column, Piece piece);


    /**
     * @brief Checks whether a move in the given column is valid.
     *
     * A move is valid if the column index is in range and
     * the column is not full.
     *
     * @param column Zero-based column index
     * @return true if the move is valid, false otherwise
     */
    bool isValidMove(int column) const;


    /**
    * @brief Checks whether the board is completely full.
    *
    * @return true if no more moves can be made, false otherwise
    */
    bool isFull() const;

    /**
    * @brief Checks whether the given piece has a winning configuration.
    *
    * @param piece The piece to check for a win
    * @return true if the piece has won, false otherwise
    */
    bool checkWin(Piece piece) const;


    /**
    * @brief Prints the current state of the board to the console.
    */
    void printBoard() const;

    /**
     * @brief Removes all pieces from the specified row.
     *
     * @param row Zero-based row index
     * @return true if the row was successfully removed, false otherwise
     */
    bool removeRow(int row);

    /**
    * @brief Removes a single piece from the specified position.
    *
    * @param row Zero-based row index
    * @param col Zero-based column index
    * @return true if the piece was removed successfully, false otherwise
    */
    bool removeCounter(int row, int col);

    /**
     * @brief Checks if there is any row eligible for removal.
     *
     * @return true if at least one removable row exists, false otherwise
     */
    bool anyRemovableRow() const;

    /**
  * @brief Checks if there is any counter eligible for removal.
  *
  * @return true if at least one removable counter exists, false otherwise
  */
    bool anyRemovableCounter() const;
};

#endif