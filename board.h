#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

struct Board {
    u_int64_t pawns, knights, rooks, bishops, queen, king;
    Board(bool cpu);
    u_int64_t sumPieces();
    void printBoard(Board cpu);
};

#endif