#ifndef PIECE_H
#define PIECE_H
#include <string>

/**
 * @brief Represents a game piece on the board.
 */
enum class Piece { EMPTY, X, O };

namespace piece_utils {

    /**
     * @brief Converts a Piece enum to a printable string.
     */
    inline std::string toString(Piece piece) {
        switch (piece) {
            case Piece::X: return "X";
            case Piece::O: return "O";
            default:       return ".";
        }
    }

} // namespace piece_util


#endif