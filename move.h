#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include "board.h"

struct Move {
    Board human;
    Board computer;
    Move(Board& hum, Board& cpu);   
   
    uint64_t tileToInt(char row, int column);
    std::vector<uint64_t> pawnMoves(uint64_t pos, Board& attacker, Board& defender);
    std::vector<uint64_t> rookMoves(uint64_t pos, Board& attacker, Board& defender);
    std::vector<uint64_t> knightMoves(uint64_t pos, Board& attacker, Board& defender);
    std::vector<uint64_t> bishopMoves(uint64_t pos, Board& attacker, Board& defender);
    std::vector<uint64_t> queenMoves(uint64_t pos, Board& attacker, Board& defender);
    std::vector<uint64_t> kingMoves(uint64_t pos, Board& attacker, Board& defender);

};

#endif