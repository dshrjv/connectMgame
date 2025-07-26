#include "ai.hpp"
#include <limits>

using namespace std;

const int INF = 10000;
const int MAX_DEPTH = 6;  // Adjustable depth for performance

int evaluateBoard(const Board& board) {
    if (board.checkWin('O')) return 1000;  // AI wins
    if (board.checkWin('X')) return -1000; // Human wins
    return 0; 
}

int minimax(Board& board, int depth, bool isMax, int alpha, int beta) {
    int score = evaluateBoard(board);
    if (score == 1000 || score == -1000 || board.isDraw() || depth >= MAX_DEPTH) 
        return score - (isMax ? depth : -depth); 

    if (isMax) {  // AI's turn
        int best = -INF;
        for (int column = 1; column <= board.N; column++) {
            if (!board.isColumnFull(column)) {
                board.makeMove(column, 'O');
                best = max(best, minimax(board, depth+1, false, alpha, beta));
                board.undoMove(column);

                alpha = max(alpha, best);
                if (beta <= alpha) break;  // Alpha-beta pruning
            }
        }
        return best;
    } else {  // Human's turn
        int best = INF;
        for (int column = 1; column <= board.N; column++) {
            if (!board.isColumnFull(column)) {
                board.makeMove(column, 'X');
                best = min(best, minimax(board, depth+1, true, alpha, beta));
                board.undoMove(column);

                beta = min(beta, best);
                if (beta <= alpha) break;  // Alpha-beta pruning
            }
        }
        return best;
    }
}

int findBestMove(Board& board, char aiPlayer) {
    int bestValue = -INF;
    int bestMove = -1;

    vector<int> moveOrder;
    for (int i = 0; i < board.N; i++) {
        int center = board.N / 2;
        int offset = (i % 2 == 0) ? i / 2 : -((i + 1) / 2);
        int col = center + offset + 1;
        if (col >= 1 && col <= board.N) {
            moveOrder.push_back(col);
        }
    }

    for (int column : moveOrder) {
        if (!board.isColumnFull(column)) {
            board.makeMove(column, aiPlayer);
            int moveValue = minimax(board, 0, false, -INF, INF);
            board.undoMove(column);

            if (moveValue > bestValue) {
                bestValue = moveValue;
                bestMove = column;
            }
        }
    } 
    return bestMove;
}
