#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <cstdint>

struct Board {
    uint64_t pawns, knights, rooks, bishops, queens, king;
    bool pos;
    bool check;
    int score;
    uint64_t enPassantTarget;
    
    Board(bool cpu);
    uint64_t sumPieces();
    int numPawns() const;
    int numRooks() const;
    int numKnights() const;
    int numBishops() const;
    int numQueens() const;
};

#endif