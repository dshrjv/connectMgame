#include "game.hpp"
#include <iostream>

using namespace std;

Game::Game(int size, int connect, bool humanFirst) : board(size, connect), humanTurn(humanFirst) {}

void Game::play() {
    char currentPlayer = humanTurn ? 'X' : 'O';

    while (true) {
        board.displayBoard();

        int column;
        if (currentPlayer == 'X') {
           humanMove();

        } else {
            column = aiMove();
            cout << "AI's pick: " << column << endl;
            board.makeMove(column, currentPlayer);
        }

        if (board.checkWin(currentPlayer)) {
            board.displayBoard();
            cout << "Player " << currentPlayer << " wins!!" << endl;
            break;
        }

        if (board.isDraw()) {
            board.displayBoard();
            cout << "It's a Tie!" << endl;
            break;
        }

        //Switch turns
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int Game::aiMove() {
    return findBestMove(board, 'O'); // AI uses 'O'
}


void Game::humanMove(){
    int column;
    cout << "Enter column (1-" << board.N << "): ";
    while (true) {
        cin >> column;
        if (column >= 1 && column <= board.N && board.makeMove(column, 'X'))
            break;
        cout << "Invalid move. Try again: ";
    
    }
}

void Game::computerMove() {
    int bestMove = findBestMove(board, 'O');
    board.makeMove(bestMove, 'O');
}
