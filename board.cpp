#include <string>
#include <cstdint>
#include "board.h"

Board::Board(bool cpu){
    if (!cpu) {
        pawns = 0x000000000000FF00;
        rooks = (1ULL << 0) | (1ULL << 7);
        knights = (1ULL << 1) | (1ULL << 6);
        bishops = (1ULL << 2) | (1ULL << 5);
        queens = 1ULL << 3;
        king = 1ULL << 4;
        pos = false;
    }
    else {
        pawns = 0x00FF000000000000;
        rooks = (1ULL << 63) | (1ULL << 56);
        knights = (1ULL << 62) | (1ULL << 57);
        bishops = (1ULL << 61) | (1ULL << 58);
        queens = 1ULL << 59;
        king = 1ULL << 60;
        pos = true;
    }
    score = 0;
    enPassantTarget = 0;
    check = false;
    castleLeft, castleRight = true;
}

uint64_t Board::sumPieces() { return  pawns | rooks | knights | bishops | queens | king; }

int Board::numPawns() const { return __builtin_popcountll(pawns); }
int Board::numRooks() const { return __builtin_popcountll(rooks); }
int Board::numKnights() const { return __builtin_popcountll(knights); }
int Board::numBishops() const { return __builtin_popcountll(bishops); }
int Board::numQueens() const { return __builtin_popcountll(queens); }