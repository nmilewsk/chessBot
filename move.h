#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <cstdint>
#include "board.h"

extern const uint64_t wrapLeftOne;
extern const uint64_t wrapLeftTwo;
extern const uint64_t wrapRightOne;
extern const uint64_t wrapRightTwo;

extern uint64_t rookAttacks[64][4096];
extern uint64_t rookMasks[64];
extern uint64_t rookMagics[64];
extern uint64_t bishopAttacks[64][4096];
extern uint64_t bishopMasks[64];
extern uint64_t bishopMagics[64];
extern uint64_t knightAttacks[64];
extern uint64_t kingAttacks[64];
extern uint64_t pawnMoves[2][64];
extern uint64_t pawnAttacks[2][64];

struct Move {
    Board human;
    Board computer;
    Move(Board& hum, Board& cpu);   
   
    uint64_t tileToInt(char column, int row);
    std::string intToTile(uint64_t pos);
    std::vector<uint64_t> pawnMoves(uint64_t pos, Board& attacker, Board& defender);
    std::vector<uint64_t> rookMoves(uint64_t pos, Board& attacker, Board& defender);
    std::vector<uint64_t> knightMoves(uint64_t pos, Board& attacker, Board& defender);
    std::vector<uint64_t> bishopMoves(uint64_t pos, Board& attacker, Board& defender);
    std::vector<uint64_t> queenMoves(uint64_t pos, Board& attacker, Board& defender);
    std::vector<uint64_t> kingMoves(uint64_t pos, Board& attacker, Board& defender);

};

#endif