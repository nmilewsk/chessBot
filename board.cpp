#include <iostream>
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
}

u_int64_t Board::sumPieces() {
    return  pawns | rooks | knights | bishops | queen | king;
}

void Board::printBoard(Board cpu) {
    for (int i = 63; i >= 0; i--) {
        if ((this->sumPieces() >> i) & 1 || (cpu.sumPieces() >> i) & 1) { std::cout << "1"; }
        else { std::cout << "0"; }
        if (i % 8 == 0) { std::cout << "\n"; }
    }
    return;
}