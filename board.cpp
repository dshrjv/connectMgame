#include "board.hpp"
#include <iostream>

using namespace std;

Board::Board(int size, int connect) : N(size), M(connect) {
    grid.resize(N, vector<char>(N, ' '));
}

void Board::displayBoard() const {
    for (int i = 0; i < N; i++) {
        cout << "+";
       
        for (int j = 0; j < N; j++) {
            cout << "---+";
        }

        cout << "\n";
        cout << "|";
       
        for (int j = 0; j < N; j++) {
            cout << " " << grid[i][j] << " |";
        }
        cout << "\n";
    }

    cout << "+";
    for (int j = 0; j < N; j++) {
        cout << "---+";
    }
    cout << "\n";

    cout << " ";
    for (int j = 1; j <= N; j++) {
        cout << " " << j << "  ";
    }

    cout << "\n";
}

bool Board::isColumnFull(int col) const {
    col -= 1;
    return grid[0][col] != ' ';
}

bool Board::makeMove(int col, char player) {
    col -= 1;
    for (int i = N - 1; i >= 0; i--) {
        if (grid[i][col] == ' ') {
            grid[i][col] = player;
            return true;
        }
    }
    return false;
}


bool Board::checkWin(char player) const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == player) {
                if (checkDirection(i, j, 1, 0, player) || checkDirection(i, j, 0, 1, player) ||
                    checkDirection(i, j, 1, 1, player) || checkDirection(i, j, 1, -1, player)) 
                    return true;
            }
        }
    }
    return false;
}

bool Board::isDraw() const {
    for (int i = 0; i < N; i++) {
        if (!isColumnFull(i)) return false;
    }
    return true;
}

bool Board::checkDirection(int row, int col, int dRow, int dCol, char player) const {
    int count = 0;

    for (int i = 0; i < M; i++) {
        int r = row + i * dRow;
        int c = col + i * dCol;

        if (r >= 0 && r < N && c >= 0 && c < N) {
            if (grid[r][c] == player) {
                count++;
                if (count == M) {
                    return true;
                } 
            } else {
                break;
            }
        } else {
            break;
        }
    }
    return false;
}

void Board::undoMove(int column) {
    column -= 1; 
    for (int row = 0; row < N; row++) {
        if (grid[row][column] != ' ') {
            grid[row][column] = ' ';
            return;

        }
    }

    cout << "Warning: Attempted to undo move in an empty column " << column + 1 << endl;
}

