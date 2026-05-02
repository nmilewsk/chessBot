#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

struct Board {
    uint64_t pawns, knights, rooks, bishops, queen, king;
    bool top;
    std::string color;
    int score;
    int numPawns, numRooks, numKnights, numBishops, numQueens, numKings;
    std::vector<uint64_t> pawnPositions, rookPositions, knightPositions, bishopPositions, queenPositions, kingPositions;
    
    Board(bool cpu);
    uint64_t sumPieces();
    void setColor(std::string choice);
};

#endif