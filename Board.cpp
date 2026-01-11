#include "Board.h"
#include <iostream>

Board::Board() : grid(ROWS, std::vector<Piece>(COLS, Piece::EMPTY)) {}

bool Board::dropPiece(int column, Piece piece) {
    if (column < 0 || column >= COLS) return false;
    for (int i = ROWS - 1; i >= 0; --i) {
        if (grid[i][column] == Piece::EMPTY) {
            grid[i][column] = piece;
            return true;
        }
    }
    return false;
}

bool Board::isValidMove(int column) const {
    return column >= 0 && column < COLS && grid[0][column] == Piece::EMPTY;
}

bool Board::isFull() const {
    for (int j = 0; j < COLS; ++j)
        if (grid[0][j] == Piece::EMPTY) {
            return false;
        }
    return true;
}

bool Board::checkWin(Piece piece) const {
    // horizontal
    for (int row = 0; row < ROWS; ++row)
        for (int col = 0; col <= COLS - 4; ++col)
            if (grid[row][col] == piece && grid[row][col+1] == piece &&
                grid[row][col+2] == piece && grid[row][col+3] == piece) {
                return true;
                }



    // vertical
    for (int col = 0; col < COLS; ++col)
        for (int row = 0; row <= ROWS - 4; ++row)
            if (grid[row][col] == piece && grid[row+1][col] == piece &&
                grid[row+2][col] == piece && grid[row+3][col] == piece) {
                return true;
            }

    // \ diagonal
    for (int row = 0; row <= ROWS - 4; ++row)
        for (int col = 0; col <= COLS - 4; ++col)
            if (grid[row][col] == piece && grid[row+1][col+1] == piece &&
                grid[row+2][col+2] == piece && grid[row+3][col+3] == piece) {
                return true;
            }

    // / diagonal
    for (int row = 3; row < ROWS; ++row)
        for (int col = 0; col <= COLS - 4; ++col)
            if (grid[row][col] == piece && grid[row-1][col+1] == piece &&
                grid[row-2][col+2] == piece && grid[row-3][col+3] == piece) {
                return true;
            }

    return false;
}

void Board::printBoard() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << piece_utils::toString(cell) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "0 1 2 3 4 5 6\n\n";
}

// Remove row only if it contains at least one piece
bool Board::removeRow(int row) {
    if (row < 0 || row >= ROWS) {
        return false;
    }
    bool hasPiece = false;
    for (const auto& cell : grid[row])
        if (cell != Piece::EMPTY) {
            hasPiece = true;
        }
    if (!hasPiece) {
        return false;
    }

    for (int r = row; r > 0; --r)
        grid[r] = grid[r - 1];

    grid[0] = std::vector<Piece>(COLS, Piece::EMPTY);
    return true;
}

// Remove counter only if it exists
bool Board::removeCounter(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    if (grid[row][col] == Piece::EMPTY) {
        return false;
    }

    grid[row][col] = Piece::EMPTY;

    // Gravity
    for (int r = row; r > 0; --r)
        grid[r][col] = grid[r-1][col];
    grid[0][col] = Piece::EMPTY;

    return true;
}


bool Board::anyRemovableRow() const {
    for (const auto& row : grid)
        for (const auto& cell : row)
            if (cell != Piece::EMPTY) {
                return true;
            }
    return false;
}

bool Board::anyRemovableCounter() const {
    for (const auto& row : grid)
        for (const auto& cell : row)
            if (cell != Piece::EMPTY) {
                return true;
            }
    return false;
}
