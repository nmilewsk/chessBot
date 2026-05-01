#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include "board.h"

Board::Board(bool cpu){
    if (!cpu) {
        pawns = 0x000000000000FF00;
        rooks = (1ULL << 0) | (1ULL << 7);
        knights = (1ULL << 1) | (1ULL << 6);
        bishops = (1ULL << 2) | (1ULL << 5);
        queen = 1ULL << 3;
        king = 1ULL << 4;
    }
    else {
        pawns = 0x00FF000000000000;
        rooks = (1ULL << 63) | (1ULL << 56);
        knights = (1ULL << 62) | (1ULL << 57);
        bishops = (1ULL << 61) | (1ULL << 58);
        queen = 1ULL << 60;
        king = 1ULL << 59;
    }
    score = 0;
}

u_int64_t Board::sumPieces() {
    return  pawns | rooks | knights | bishops | queen | king;
}

void Board::setColor(std::string choice) {
    color = choice;
    return;
}