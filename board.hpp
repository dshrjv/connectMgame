#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

using namespace std;

class Board {
    public:
        int N;
        int M;
        vector<vector<char>> grid;
        Board(int size, int connect);
        void displayBoard() const;
        bool isColumnFull(int col) const;
        bool isDraw() const;
        bool checkWin(char player) const;
        bool makeMove(int col, char player);
        void undoMove(int column);
    private:
        bool checkDirection(int row, int col, int dCol, int dRow, char player) const;
        
};

#endif