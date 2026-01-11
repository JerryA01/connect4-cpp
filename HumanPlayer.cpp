#include "HumanPlayer.h"
#include <iostream>
#include "Piece.h"

HumanPlayer::HumanPlayer(const std::string& name, Piece piece)
    : Player(name, piece) {}

int HumanPlayer::makeMove(Board& board) {
    char action;
     while (true) {
        std::cout << name << " ("
                  << piece_utils::toString(piece)
                  << "), choose action: D=Drop, R=Remove Row, C=Remove Counter: ";
        std::cin >> action;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        // DROP PIECE
        if (action == 'D' || action == 'd') {
            int column;
            while (true) {
                std::cout << "Enter column (0-6): ";
                std::cin >> column;
                if (std::cin.fail() || column < 0 || column >= 7) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid column. Try again.\n";
                    continue;
                }
                if (board.isValidMove(column)) return column;
                std::cout << "Column full. Try again.\n";
            }
        }
        // REMOVE ROW
        if (action == 'R' || action == 'r') {
            if (!board.anyRemovableRow()) {
                std::cout << "No rows available to remove.\n";
                continue;
            }
            int row;
            while (true) {
                std::cout << "Enter row to remove (0-5): ";
                std::cin >> row;
                if (std::cin.fail() || row < 0 || row >= 6) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid row. Try again.\n";
                    continue;
                }
                if (board.removeRow(row)) {
                    constexpr int REMOVE_ROW_BASE = -100;
                    if (board.checkWin(piece)) {
                        std::cout << name << " (" << piece_utils::toString(piece) << ") wins!\n";
                    }
                    return REMOVE_ROW_BASE - row;
                }

                std::cout << "Cannot remove: row empty. Try again.\n";
            }
        }

        // REMOVE COUNTER
        if (action == 'C' || action == 'c') {
            if (!board.anyRemovableCounter()) {
                std::cout << "No counters available to remove.\n";
                continue;
            }
            int row, column;
            while (true) {
                std::cout << "Enter row (0-5): ";
                std::cin >> row;
                std::cout << "Enter column (0-6): ";
                std::cin >> column;

                if (std::cin.fail() || row < 0 || row >= 6 || column < 0 || column >= 7) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid row/column. Try again.\n";
                    continue;
                }

                if (board.removeCounter(row, column)) {
                    constexpr int REMOVE_COUNTER_BASE = -200;
                    if (board.checkWin(piece)) {
                        std::cout << name << " (" << piece_utils::toString(piece) << ") wins!\n";
                    }
                    return REMOVE_COUNTER_BASE - (row*10 + column);
                }
                std::cout << "Cannot remove: no counter at that position. Try again.\n";
            }
        }
        else {
            std::cout << "Unknown action. Try again.\n";
        }
    }
}