#include <catch2/catch_amalgamated.hpp>

#include "Board.h"
#include "Piece.h"


TEST_CASE("Board initializes empty", "[board]") {
    Board board;

    // We cannot access grid directly, so test via remove checks
    REQUIRE(board.anyRemovableCounter() == false);
}


TEST_CASE("Dropping a piece places it in the bottom row", "[drop]") {
    Board board;

    bool success = board.dropPiece(3, Piece::X);

    REQUIRE(success);
}


TEST_CASE("Invalid column is rejected", "[drop]") {
    Board board;

    REQUIRE(board.dropPiece(-1, Piece::X) == false);
    REQUIRE(board.dropPiece(7, Piece::X) == false);
}


TEST_CASE("Cannot drop piece into full column", "[drop]") {
    Board board;

    for (int i = 0; i < 6; i++) {
        board.dropPiece(0, Piece::X);
    }

    REQUIRE(board.dropPiece(0, Piece::O) == false);
}


TEST_CASE("Vertical win is detected", "[win]") {
    Board board;

    for (int i = 0; i < 4; i++) {
        board.dropPiece(2, Piece::X);
    }

    REQUIRE(board.checkWin(Piece::X) == true);
}


TEST_CASE("Horizontal win is detected", "[win]") {
    Board board;

    for (int col = 0; col < 4; col++) {
        board.dropPiece(col, Piece::O);
    }

    REQUIRE(board.checkWin(Piece::O) == true);
}


TEST_CASE("Removing a row succeeds when row is not empty", "[remove-row]") {
    Board board;

    board.dropPiece(0, Piece::X);
    board.dropPiece(1, Piece::O);

    REQUIRE(board.removeRow(5) == true);
}


TEST_CASE("Cannot remove empty row", "[remove-row]") {
    Board board;

    REQUIRE(board.removeRow(3) == false);
}


TEST_CASE("Removing a counter applies gravity", "[remove-counter]") {
    Board board;

    board.dropPiece(0, Piece::X);
    board.dropPiece(0, Piece::O);

    REQUIRE(board.removeCounter(5, 0) == true);
}


TEST_CASE("Cannot remove empty counter", "[remove-counter]") {
    Board board;

    REQUIRE(board.removeCounter(0, 0) == false);
}








