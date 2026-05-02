#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include "board.h"
#include "move.h"

Move::Move(Board& hum, Board& cpu) : human(hum), computer(cpu) { }

uint64_t Move::tileToInt(char column, int row) {
    int newColumn = column - 'a';
    uint64_t spot = 2^(newColumn - (8*row));
    return spot;
}

std::string Move::intToTile(uint64_t pos) {
    return "\n";
}

std::vector<uint64_t> pawnMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    uint64_t defBoard = defender.sumPieces();
    uint64_t wholeBoard = (defender.sumPieces() | attacker.sumPieces());
    if (attacker.top) {
        uint64_t front = (pos >> 8);
        if (!(front & wholeBoard)) {  }

    }
    return moves;
}

std::vector<uint64_t> rookMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    return moves;
}

std::vector<uint64_t> knightMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    return moves;
}

std::vector<uint64_t> bishopMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    return moves;
}

std::vector<uint64_t> queenMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    return moves;
}

std::vector<uint64_t> kingMoves(uint64_t pos, Board& attacker, Board& defender) {
    std::vector<uint64_t> moves;
    return moves;
}


