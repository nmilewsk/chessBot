#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <cstdint>
#include "board.h"

Board::Board(bool cpu){
    if (!cpu) {
        pawns = 0x000000000000FF00;
        for (int i = 0; i < 8; i++) { pawnPositions.push_back(1ULL << (15 - i)); }
        rooks = (1ULL << 0) | (1ULL << 7);
        rookPositions.push_back(1ULL << 0);
        rookPositions.push_back(1ULL << 7);
        knights = (1ULL << 1) | (1ULL << 6);
        knightPositions.push_back(1ULL << 1);
        knightPositions.push_back(1ULL << 6);
        bishops = (1ULL << 2) | (1ULL << 5);
        bishopPositions.push_back(1ULL << 2);
        bishopPositions.push_back(1ULL << 5);
        queen = 1ULL << 3;
        queenPositions.push_back(1ULL << 3);
        king = 1ULL << 4;
        kingPositions.push_back(1ULL << 4);
        top = false;
    }
    else {
        pawns = 0x00FF000000000000;
        for (int i = 0; i < 8; i++) { pawnPositions.push_back(1ULL << (55 - i)); }
        rooks = (1ULL << 63) | (1ULL << 56);
        rookPositions.push_back(1ULL << 63);
        rookPositions.push_back(1ULL << 56);
        knights = (1ULL << 62) | (1ULL << 57);
        knightPositions.push_back(1ULL << 62);
        knightPositions.push_back(1ULL << 57);
        bishops = (1ULL << 61) | (1ULL << 58);
        bishopPositions.push_back(1ULL << 61);
        bishopPositions.push_back(1ULL << 58);
        queen = 1ULL << 59;
        queenPositions.push_back(1ULL << 59);
        king = 1ULL << 60;
        kingPositions.push_back(1ULL << 60);
        top = true;
    }
    score = 0;
    numPawns = 8;
    numRooks = 2;
    numBishops = 2;
    numKnights = 2;
    numQueens = 1;
    numKings = 1;
}

uint64_t Board::sumPieces() {
    return  pawns | rooks | knights | bishops | queen | king;
}

void Board::setColor(std::string choice) {
    color = choice;
    return;
}