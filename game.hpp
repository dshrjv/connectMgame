#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"
#include "ai.hpp"

class Game {
public:
    Game(int size, int connect, bool humanFirst);
    void play();

    int aiMove();

private:
    Board board;
    bool humanTurn;
    void humanMove();
    void computerMove();
    void switchTurn();




};




#endif
