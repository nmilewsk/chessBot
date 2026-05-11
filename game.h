#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include "board.h"


struct Game {
    Board human, computer;
    Print display;
    bool checkmate;
    int turn;
    Game(bool white);

    void updateCheckmate();
};

struct Print {
    const Board& w;
    const Board& b;

    Print(const Board& white, const Board& black);

    void printBoard(std::ostream& out = std::cout);

private:
    std::string getLabel(uint64_t sq);
};


#endif