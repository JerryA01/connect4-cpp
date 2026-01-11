#include "Game.h"
#include <iostream>

Game::Game(Player& p1, Player& p2)
    : player1(p1), player2(p2) {}

void Game::endGame() {
    gameOver = true;
}

void Game::start() {
    Player* current = &player1;

    board.printBoard();

    while (!gameOver) {
        int move = current->makeMove(board);

        if (move <= -100 && move > -200) {
            int row = -(move + 100);
            board.printBoard();
        }
        else if (move <= -200) {
            board.printBoard();
        }
        else {
            board.dropPiece(move, current->getPiece());
            board.printBoard();

            if (board.checkWin(current->getPiece())) {
                std::cout << current->getName() << " wins!\n";
                endGame();
                break;
            }
        }

        if (board.isFull()) {
            std::cout << "It's a draw!\n";
            endGame();
            break;
        }

        current = (current == &player1) ? &player2 : &player1;
    }
}
