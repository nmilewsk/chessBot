#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

struct Board {
    uint64_t pawns, knights, rooks, bishops, queen, king;
    std::string color;
    int score;
    int numPawns, numRooks, numKnights, numBishops, numQueens, numKings;
    Board(bool cpu);
    uint64_t sumPieces();
    void setColor(std::string choice);
};

#endif