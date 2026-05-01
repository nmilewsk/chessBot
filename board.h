#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

struct Board {
    u_int64_t pawns, knights, rooks, bishops, queen, king;
    std::string color;
    int score;
    Board(bool cpu);
    u_int64_t sumPieces();
    void setColor(std::string choice);
};

#endif